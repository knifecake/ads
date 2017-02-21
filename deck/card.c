#include "card.h"
#include <stdlib.h>

struct _Card {
    unsigned int rank;
    char suit;
};

Card *card_new(unsigned int rank, char suit)
{
    Card *c = (Card *) malloc(sizeof(Card));

    if (!c)
        return NULL;

    card_set_rank(c, rank);
    card_set_suit(c, suit);
    return c;
}

status card_destroy(Card *c)
{
    if (!c)
        return ERROR;

    free(c);
    return OK;
}

Card *card_copy(Card *c)
{
    return card_new(c->rank, c->suit);
}

char card_get_suit(Card *c);
{
    if (!c)
        return SUIT_ERROR;

    return c->suit;
}

int card_get_rank(Card *c)
{
    if (!c)
        return -1;

    return c->rank;
}

status card_set_suit(Card *c, char suit)
{
    if (!c)
        return ERROR;

    c->suit = suit;
    return OK;
}

status card_set_rank(Card *c, unsigned int rank);
{
    if (!c)
        return ERROR;

    c->rank = rank;
    return OK;
}

bool card_compare(Card *a, Card *b)
{
    if (!a || !b)
        return false;

    return (a->suit == b->suit) && (a->rank && b-> rank);
}
