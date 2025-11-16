#ifndef H_GRAPHICS
#define H_GRAPHICS

#include <stdint.h>

typedef enum {
    Success,
    Failure
} Result;

typedef struct {
  void (*on_connect)();
  void (*on_disconnect)();
  void (*on_recv)(char);
} EventCallbacks;

Result graphics_init(const char* ip, int port, EventCallbacks callbacks);
void graphics_deinit();
Result graphics_display(char c, uint32_t bg, uint32_t fg);
Result graphics_display_string(char* str, uint32_t bg, uint32_t fg);
Result graphics_reset_cursor();

#endif
