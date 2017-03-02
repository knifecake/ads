#include "item.h"

struct _Item {
    int foo;
};

Item *item_new(int foo)
{
    Item *item = (Item *) malloc(sizeof(Item));
    item->foo = foo;
    return item;
}

void item_destroy(Item *item)
{
    if (item)
        free(item);
}


bool item_compare(const Item *a, const Item *b)
{
    return a && b && a->foo == b->foo;
}

Item *item_copy(const Item *original)
{
    return item_new(original->foo);
}

int item_get_foo(const Item *item)
{
    return item->foo;
}
