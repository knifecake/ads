#include "../support/item.h"
#include "../tester/tester.h"
#include "set.h"

int main(void)
{
    printf("\nTesting a set...\n");

    Set *s, *t, *u;
    s = new_set();
    t = new_set();
    u = new_set();

    Item *i1, *i2, *i3, *i4, *i5;
    i1 = new_item(1);
    i2 = new_item(2);
    i3 = new_item(3);
    i4 = new_item(4);
    i5 = new_item(5);

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
    set_insert(t, i2);
    set_insert(t, i4);

    assert("Can unite 2 non-disjoint sets",
            set_union(s, t, u));

    assert("Union has correct number of elements",
            set_size(u) == 4);

    assert("Can empty set",
            set_empty(u) == OK);

    assert("Can intersect sets",
            set_intersection(s, t, u));

    assert("Intersection has correct number of elements",
            set_size(u) == 1);

    set_free(s);
}
