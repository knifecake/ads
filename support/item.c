#include "item.h"

Item *new_item(int foo)
{
    Item *item = (Item *) malloc(sizeof(Item));
    item->foo = foo;
    return item;
}
