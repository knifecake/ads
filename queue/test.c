#include "queue.h"
#include "../support/item.h"
#include "../tester/tester.h"

int main(void)
{
    printf("Testing a queue...\n");

    Queue *q;
    Item *i = item_new(2);

    q = queue_new((void *(*)(const void *)) &item_copy, (void (*)(void *))&item_destroy);
    assert("can create queue",
            q != NULL);

    assert("can enqueue an item",
            queue_enqueue(q, i));

    assert("can dequeue an item",
            item_compare((Item *)queue_dequeue(q), i));

    queue_destroy(q);
    assert("can destroy queue", true);

    item_destroy(i);
    return 0;
}
