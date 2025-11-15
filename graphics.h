#ifndef H_GRAPHICS
#define H_GRAPHICS

typedef enum {
    Success,
    Failure
} Result;

typedef struct {
    void(*)() on_connect;
    void(*)() on_disconnect;
    void(*)(char) on_recv;
} EventCallbacks

Result graphics_init(const char* ip, int port, EventCallbacks callbacks);
void graphics_deinit();
Result graphics_display(char msg, unsigned char r, unsigned char g, unsigned char b);
Result graphics_display_string(char* msg, unsigned char r, unsigned char g, unsigned char b);

#endif
