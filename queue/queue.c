#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#define REALLOC_BUFFER 10

struct _Queue {
    void **data;
    size_t size, capacity;
    size_t head, tail;

    void (*item_destroy_function)(void *);
    void *(*item_copy_function)(const void *);
};

Queue *queue_new(void *(*item_copy_function)(const void *), void (*item_destroy_function)(void *))
{
    if (!item_destroy_function || !item_copy_function) return NULL;

    Queue *q = malloc(sizeof(Queue));
    if (!q) return NULL;

    q->size = 0;
    q->head = 0;
    q->tail = 0;
    q->capacity = REALLOC_BUFFER;
    q->item_destroy_function = item_destroy_function;
    q->item_copy_function = item_copy_function;

    q->data = malloc(q->capacity * sizeof(void *));
    if (!q->data)
    {
        free(q);
        return NULL;
    }

    return q;
}

void queue_destroy(Queue *q)
{
    if (!q) return;

    for (int i = 0; i < q->size; i++)
        q->item_destroy_function(q->data[(q->head + i) % q->capacity]);

    free(q->data);
    free(q);
}

Queue *queue_enqueue(Queue *q, void *v)
{
    if (!q || !v) return NULL;

    if (q->tail >= q->capacity)
    {
        void **new_data = realloc(q->data, (REALLOC_BUFFER + q->capacity) * sizeof(void *));
        if (!new_data) return NULL;

        q->data = new_data;
        q->capacity += REALLOC_BUFFER;
    }

    void *copy = q->item_copy_function(v);
    if (!copy) return NULL; // should we resize the queue?

    q->data[q->tail++] = copy;
    return q;
}

void *queue_dequeue(Queue *q)
{
    if (!q) return NULL;

    return q->data[q->head++];
}
