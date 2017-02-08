#include "../tester/tester.h"
#include "item.h"

int main(void)
{
    printf("Testing an item...\n");

    Item *i, *j, *k;
    i = item_new(0);
    k = item_new(1);

    assert("Can create an item",
            i != NULL);


    j = item_copy(i);
    assert("Can copy an item",
            j != NULL);

    assert("Can compare two items",
            item_compare(i, j) && !item_compare(i, k));

    assert("Can obtain the foo property of an item",
            item_get_foo(i) == 0);

    item_destroy(i);
    return 0;
}
