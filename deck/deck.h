#include "card.h"

typedef struct _Deck Deck;

Deck *deck_new();
status deck_destroy(Deck *d);
status deck_shuffle(Deck *d);
