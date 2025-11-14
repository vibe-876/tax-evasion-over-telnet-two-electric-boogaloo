#include "queue.h"
#include <stdlib.h>


void enqueue(Queue* queue, Action action) {
  if(queue->tail >= MAX_ACTIONS) return;
  queue->queue[++queue->tail] = action;
}
  
Action dequeue(Queue* queue) {
  if(queue->tail == 0) return(none);
  return(queue->queue[queue->tail--]);
}
