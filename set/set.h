#include <stdlib.h>
#include <stdbool.h>

typedef struct _Set Set;

typedef enum {ERROR, OK} status;

Set *set_new();
void set_destroy(Set *set, void (*item_destroy)(void *));
status set_empty(Set *set);
int set_size(Set *set);
status set_insert(Set *set, void *item);
bool set_search(Set *haystack, void *needle);
status set_union(Set *a, Set *b, Set *r);
status set_intersection(Set *a, Set *b, Set *r);
