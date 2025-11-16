#include "graphics.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

static int server_sock;
static int client_sock;
static EventCallbacks cb;

enum InputState {
    NORMAL,
    IAC
};

/// Privately scoped function that runs the main input loop
void* input_loop(void* arg) {
    static enum InputState state = NORMAL;

    unsigned char buf[1];
    unsigned char consumer[3];

    for (;;) {
        // Wait for next input
        recv(client_sock, buf, 1, 0);

        // Consuming IAC
        switch (buf[0]) {
            case 255:
                if (state == NORMAL) {
                    state = IAC;
                } else {
                    state = NORMAL;
                    cb.on_recv(255);
                }

                break;

            case 250:   // 2 bytes and fucks with everything
                recv(client_sock, consumer, 2, 0);
                break;

            case 251:   // 3 bytes
            case 252:
            case 253:
            case 254:
                if (state == IAC) {
                    recv(client_sock, consumer, 3, 0);
                    state = NORMAL;
                    break;
                }

                // Else fall through to default case

            default:
                if (state == IAC) { // 2 bytes
                    recv(client_sock, consumer, 2, 0);
                    state = NORMAL;
                } else {            // Run on_recv
                    cb.on_recv(buf[0]);
                }

                break;
        }
    }

    return NULL;
}


/// Sets up the server socket and waits for a connection
Result graphics_init(const char* ip, int port, EventCallbacks callbacks) {
    // Setting up connection
    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1)
        return Failure;

    // Bind to the given ip and port
    struct sockaddr_in addr, cli_addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    bind(server_sock, (const struct sockaddr*) &addr, sizeof(addr));

    // Wait for a connection
    if (listen(server_sock, 1) == -1)
        return Failure;

    socklen_t cli_len = sizeof(cli_addr);
    client_sock = accept(server_sock, (struct sockaddr*) &cli_addr, &cli_len);

    if (client_sock == -1)
        return Failure;

    // Running callback
    cb = callbacks;
    cb.on_connect();

    // Setting up input thread
    pthread_t thread;
    pthread_create(&thread, NULL, input_loop, NULL);

    // Returning success
    return Success;
}


/// Shuts down the server
void graphics_deinit() {
    shutdown(server_sock, SHUT_RDWR);
    close(server_sock);
    server_sock = -1;
    cb.on_disconnect();
}


/// Sends a single ANSI colored block to the connected
Result graphics_display(char c, uint32_t bg, uint32_t fg) {
    // Construct the message
    char msg[50] = {0};

    sprintf(msg, "\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm%c\033[0m", 
        (fg >> 16) & 0xFF, (fg >> 8) & 0xFF, (fg) & 0xFF,
        (bg >> 16) & 0xFF, (bg >> 8) & 0xFF, (bg) & 0xFF, c);

    // Send and check for failure/success
    ssize_t s = send(client_sock, msg, sizeof(msg), 0); // TODO: IAC handling

    if (s == -1)
       return Failure;

    return Success;
}


/// Sends a ANSI colored string to the connected user
Result graphics_display_string(char* str, uint32_t bg, uint32_t fg) {
    // Construct the message 
    int msg_len = strnlen(str, 32*32 + 1); // TODO change this to MAP_SIZE
    char msg[msg_len + 50];

    sprintf(msg, "\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm%s\033[0m", 
        (fg >> 16) & 0xFF, (fg >> 8) & 0xFF, (fg) & 0xFF,
        (bg >> 16) & 0xFF, (bg >> 8) & 0xFF, (bg) & 0xFF, str);

    // Send and check for failure/success
    ssize_t s = send(client_sock, msg, msg_len + 50, 0); // TODO: IAC handling

    if (s == -1)
       return Failure;

    return Success;
}



/*

void test() {
    printf("test\n");
}

void testp(char c) {
    printf("Input: %c\n", c);
}

int main(void) {
    EventCallbacks c = (EventCallbacks) {test, test, testp};

    if (graphics_init("127.0.0.1", 8080, c) != Success) {
        printf("error: init\n");
        return 1;
    }

    if (graphics_display('x', 0xFF, 0xFF0000) != Success) {
        printf("error: display\n"); 
        return 1;
    }

    for (;;) {}

    graphics_deinit(); 
}

*/
