#include "graphics.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static int server_sock;

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
    listen(server_sock, 1);

    int cli_len = sizeof(cli_addr);
    accept(server_sock, (struct sockaddr*) &cli_addr, &cli_len);

    return Success;
}


/// Shuts down the server
void graphics_deinit() {
    shutdown(server_sock, SHUT_RDWR);
    close(server_sock);
    server_sock = -1;
}


/// Sends a single ANSI colored block to the connected
Result graphics_display(char c, uint32_t bg, uint32_t fg) {
    // Construct the message
    char msg[50] = {0};

    sprintf(msg, "\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm%c\003[0m", 
        (fg >> 16) & 0xFF, (fg >> 8) & 0xFF, (fg) & 0xFF,
        (bg >> 16) & 0xFF, (bg >> 8) & 0xFF, (bg) & 0xFF);

    // Send and check for failure/success
    ssize_t s = send(server_sock, msg, sizeof(msg), 0);

    if (s == -1)
       return Failure;

    return Success;
}


/// Sends a ANSI colored string to the connected user
Result graphics_display_string(char* msg, uint32_t bg, uint32_t fg) {

}

void test() {}
void testp(char c) {}

int main(void) {
    EventCallbacks cb = (EventCallbacks) {test, test, testp};

    if (graphics_init("127.0.0.1", 8080, cb) != Success) 
        printf("error: init");
    if (graphics_display('x', 0xFF, 0xFF0000) != Success)
        printf("error: display"); 

    graphics_deinit(); 
}
