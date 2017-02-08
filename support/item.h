#include <stdlib.h>
#include <stdbool.h>

typedef struct _Item Item;

Item *item_new(int foo);
void item_destroy(Item *item);
bool item_compare(Item *a, Item *b);
Item *item_copy(Item *original);
