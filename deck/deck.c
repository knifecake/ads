#include "deck.h"
#include <stdlib.h>

#define DECK_RESIZE_INTERVAL 50

struct _Deck {
    Card **cards;
    unsigned int size;
    unsigned int capacity;
};

void swap(Card **a, Card **b);
bool deck_empty(Deck *d);

Deck *deck_new()
{
    Deck *d = malloc(sizeof(Deck));
    if (!d)
        return NULL;

    d->cards = malloc(DECK_RESIZE_INTERVAL * sizeof(Card *));
    if (!d->cards)
    {
        free(d);
        return NULL;
    }

    d->capacity = DECK_RESIZE_INTERVAL;
    d->size = 0;
    return d;
}

status deck_destroy(Deck *d)
{
    if (!d)
        return ERROR;

    for (int i = 0; i < d->size; i++)
        card_destroy(d->cards[i]);

    free(d);
    return OK;
}

status deck_push(Deck *d, Card *c)
{
    if (!c || !d)
        return ERROR;

    if (d->size == d-> capacity)
    {
        Card **new_buffer = realloc(d->cards, (d->capacity + DECK_RESIZE_INTERVAL) * sizeof(Card *));
        if (!new_buffer)
            return ERROR;
        d->cards = new_buffer;
    }

    Card *new = card_copy(c);
    if (!new)
        return ERROR;

    d->cards[d->size] = new;
    return OK;
}

Card *deck_pop(Deck *d)
{
    if (!d || deck_empty(d))
        return NULL;

    Card *last = d->cards[d->size - 1];
    d->size--;
    return last;
}

Card *deck_shift(Deck *d)
{
    if (!d || deck_empty(d))
        return NULL;

    Card *first = d->cards[0];
    for (int i = 0; i < d->size - 1; i++)
        d->cards[i] = d->cards[i + 1];

    return first;
}

status deck_shuffle(Deck *d)
{
    if (!d)
        return ERROR;

    for (int i = 0; i < d->size; i++)
    {
        unsigned int a, b;
        a = rand() / RAND_MAX * d->size;
        b = rand() / RAND_MAX * d->size;

        swap(&d->cards[a], &d->cards[b]);
    }

    return OK;
}

void swap(Card **a, Card **b)
{
    Card *tmp = *b;
    *a = *b;
    *b = tmp;
}

bool deck_empty(Deck *d)
{
    if (!d || d->size == 0)
        return true;

    return false;
}
