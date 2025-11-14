typedef enum {
    Success,
    Failure
} Result;

typedef struct {
    void(*)() on_connect;
    void(*)() on_disconnect;
    void(*)() on_recv;
} EventCallbacks

Result graphics_init(const char* ip, int port, EventCallbacks callbacks);
void graphics_deinit(Server* server);
Result graphics_display(char msg, char r, char g, char b);
Result graphics_display_string(char* msg, char r, char g, char b);
