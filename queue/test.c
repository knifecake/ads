#include "queue.h"
#include "../support/item.h"
#include "../tester/tester.h"

bool test_with_numbers(Queue *q, unsigned int n)
{
    if (!q || n < 1) return false;

    for (int i = 0; i < n; i++)
    {
        Item *j = item_new(i);
        queue_enqueue(q, j);
        item_destroy(j);
    }

    for (int i = 0; i < n; i++)
    {
        Item *j = queue_dequeue(q);
        if (!q || item_get_foo(j) != i) return false;
        item_destroy(j);
    }

    return true;
}

int main(void)
{
    printf("Testing a queue...\n");

    Queue *q;
    Item *j, *i = item_new(2);

    q = queue_new((void *(*)(const void *)) &item_copy, (void (*)(void *))&item_destroy);
    assert("can create queue",
            q != NULL);

    assert("can enqueue an item",
            queue_enqueue(q, i));

    assert("can dequeue an item",
            item_compare(j = (Item *)queue_dequeue(q), i));

    assert("can store 15 elements in the queue and retrieve them properly",
            test_with_numbers(q, 15));

    assert("can store 1500 elements in the queue and retrieve them properly",
            test_with_numbers(q, 1500));

    queue_destroy(q);
    assert("can destroy queue", true);

    item_destroy(i);
    item_destroy(j);
    return 0;
}
