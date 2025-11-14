#define MAX_ACTIONS 16

typedef enum ActionEnum {
  move,
  attack,
  none
} Action;

typedef struct QueueStruct {
  Action queue[MAX_ACTIONS];
  char tail;
} Queue;

void enqueue(Queue *queue, Action action);
Action dequeue(Queue *queue);
