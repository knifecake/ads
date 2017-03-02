#include <stdlib.h>
#include <stdbool.h>

typedef struct _Item Item;

Item *item_new(int foo);
void item_destroy(Item *item);
bool item_compare(const Item *a, const Item *b);
Item *item_copy(const Item *original);

int item_get_foo(const Item *item);
