#include "set.h"

#define CAPACITY_INCR 2

struct _Set {
    void **store;
    unsigned int capacity;
    unsigned int size;
};

bool set_full(Set *set);

Set *new_set()
{
    Set *set = (Set *) malloc(sizeof(Set));

    set->store = malloc(CAPACITY_INCR * sizeof(void *));
    if (!set->store)
        return NULL;

    set->capacity = CAPACITY_INCR;
    set->size = 0;

    return set;
}

void set_free(Set *set)
{
    if (set)
        free(set);

    return;
}

status set_empty(Set *set)
{
    if (!set)
        return ERROR;

    for (int i = 0; i < set->size; i++)
    {
        if (set->store[i])
            free(set->store[i]);
    }

    set->size = 0;
    return OK;
}

int set_size(Set *set)
{
    if (!set)
        return -1;

    return set->size;
}

status set_insert(Set *set, void *item)
{
    if (!set)
        return ERROR;

    if (set_full(set))
    {
        void **new_store = realloc(set->store, (set->capacity + CAPACITY_INCR) * sizeof(void *));
        if (!new_store)
            return ERROR;
        else
        {
            set->store = new_store;
            set->capacity += CAPACITY_INCR;
        }
    }

    if (!set_search(set, item))
    {
        set->store[set->size] = item;
        set->size++;
        return OK;
    }
    else
        return ERROR;
}


bool set_search(Set *haystack, void *needle)
{
    for (int i = 0; i < haystack->size; i++)
    {
        if (haystack->store[i] == needle)
            return true;
    }

    return false;
}

status set_union(Set *a, Set *b, Set *r)
{
    if (!a || !b || !r)
        return ERROR;

    for (int i = 0; i < a->size; i++)
    {
        if (!set_insert(r, a->store[i]))
            return ERROR;
    }

    for (int i = 0; i < b->size; i++)
    {
        // skip duplicate elements
        if (set_search(r, b->store[i]))
            continue;

        if (!set_insert(r, b->store[i]))
            return ERROR;
    }

    return OK;
}

status set_intersection(Set *a, Set *b, Set *r)
{
    if (!a || !b || !r)
        return ERROR;

    Set *min_set, *other_set;
    if (a->size < b->size)
    {
        min_set = a;
        other_set = b;
    }
    else
    {
        min_set = b;
        other_set = a;
    }

    for (int i = 0; i < min_set->size; i++)
    {
        if (set_search(other_set, min_set->store[i]))
        {
            if (!set_search(r, min_set->store[i]))
            {
                if (!set_insert(r, min_set->store[i]))
                    return ERROR;
            }
        }
    }

    return OK;
}

bool set_full(Set *set)
{
    if (set->size == set->capacity)
        return true;

    return false;
}
