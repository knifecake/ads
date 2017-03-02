typedef struct _Queue Queue;

Queue *queue_new(void *(*item_copy_function)(const void *), void (*item_destroy_function)(void *));

void queue_destroy(Queue *q);

Queue *queue_enqueue(Queue *, void *);

void *queue_dequeue(Queue *);
