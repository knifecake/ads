#include <string.h>
#include <stdbool.h>

#define SUIT_ERROR 'e'

typedef enum {ERROR, OK} status;

typedef struct _Card Card;

Card *card_new(unsigned int rank, char suit);
status card_destroy(Card *c);
Card *card_copy(Card *c);

char card_get_suit(Card *c);
int card_get_rank(Card *c);

status card_set_suit(Card *c, char suit);
status card_set_rank(Card *c, unsigned int rank);

bool card_compare(Card *a, Card *b);
