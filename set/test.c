#include "../support/item.h"
#include "../tester/tester.h"
#include "set.h"

int main(void)
{
    printf("\nTesting a set...\n");

    Set *s, *t, *u;
    s = set_new();
    t = set_new();
    u = set_new();

    Item *i1, *i2, *i3, *i4;
    i1 = item_new(1);
    i2 = item_new(2);
    i3 = item_new(3);

    assert("Can create a set",
            s != NULL);

    assert("New set size is 0",
            set_size(s) == 0);

    assert("Can insert first element",
            set_insert(s, i1) == OK);

    assert("Can find the element we just inserted",
            set_search(s, i1));

    assert("Cannot find an item we did not insert",
            !set_search(s, i2));

    assert("Can insert one more item",
            set_insert(s, i2));

    assert("Set refuses to insert duplicate item",
            !set_insert(s, i2));

    assert("Can insert yet another item (set grows)",
            set_insert(s, i3));

    assert("Set size increases accordingly",
            set_size(s) == 3);

    // prepare for testing set_union
    i4 = item_new(4);
    set_insert(t, i2);
    set_insert(t, i4);

    assert("Can unite 2 non-disjoint sets",
            set_union(s, t, u));

    assert("Union has correct number of elements",
            set_size(u) == 4);

    assert("Can intersect sets",
            set_intersection(s, t, u));

    assert("Intersection has correct number of elements",
            set_size(u) == 1);

    assert("Can empty set",
            set_empty(s));

    set_destroy(s, (void (*)(void *)) &item_destroy);

    // TODO: figure out how to test this
    assert("Can destroy set", true);
    return 0;
}
