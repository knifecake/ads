#include "deck.h"
#include <stdlib.h>

struct _Deck {
    Card **cards;
    unsigned int size;
    unsigned int capacity;
};

void swap(Card *a, Card *b);

Deck *deck_new()
{
    return (Deck *) malloc(sizeof(Deck));
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

status deck_shuffle(Deck *d)
{
    if (!d)
        return ERROR;

    for (int i = 0; i < d->size; i++)
    {
        unsigned int a, b;
        a = rand() / RAND_MAX * d->size;
        b = rand() / RAND_MAX * d->size;

        swap(d->cards[a], d->cards[b]);
    }

    return OK;
}

void swap(Card *a, Card *b)
{
    Card *tmp = b;
    a = b;
    b = tmp;
}
