typedef enum {
    Success,
    Failure
} Result;

/* typedef struct { */
/*     void(*)() on_connect; */
/*     void(*)() on_disconnect; */
/*     void(*)() on_recv; */
/* } EventCallbacks; */

/* Result graphics_init(const char* ip, int port, EventCallbacks callbacks); */
/* void graphics_deinit(Server* server); */
Result graphics_display(unsigned char msg, unsigned char r, unsigned char g, unsigned char b);
/* Result graphics_display_string(unsigned char* msg, unsigned char r, unsigned char g, unsigned char b); */
