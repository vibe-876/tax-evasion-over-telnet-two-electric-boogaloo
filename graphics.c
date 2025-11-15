#include "graphics.h"
#include <sys/socket.h>

static int server_sock;

/// Sets up the server socket and waits for a connection
Result graphics_init(const char* ip, int port, EventCallbacks callbacks) {
    // Setting up connection
    server_sock = socket(AF_INET, SOCK_STREAM);

    if (server_sock == -1)
        return Failure;

    // Bind to the given ip and port
    bind(server_sock, (const struct sockaddr*) &name, sizeof(name));

    // Wait for a connection
    listen(server_sock, 1);

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
    const void msg[] = {
        "\033[38;2;", (fg >> 16) & 0xFF, ';', (fg >> 8) & 0xFF, ';', (fg) & 0xFF, 'm',
        "\033[48;2;", (bg >> 16) & 0xFF, ';', (bg >> 8) & 0xFF, ';', (bg) & 0xFF, 'm',
        c,
        "\033[0m"
    };

    // Send and check for failure/success
    ssize_t s = send(server_sock, msg, sizeof(msg), 0);

    if (s == -1)
        return Failure;

    return Success;
}


/// Sends a ANSI colored string to the connected user
Result graphics_display_string(char* msg, uint32_t bg, uint32_t fg) {

}


int main(void) {
    if (graphics_init("", 16000) != Success) 
        printf("error: init");
    if (graphics_display('x', 0xFF, 0xFF0000) != Success);
        printf("error: display");

    graphics_deinit();
}
