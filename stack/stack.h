/**
 * A poor stack implementation by Elias Hernandis.
 *
 * 20170202
 */

#include <stdio.h> // necessary? (because of NULL)
#include <stdlib.h>
#include <stdbool.h>


#define MAX_STACK_SIZE 3

typedef struct _Stack Stack;
typedef enum {OK = 0, ERROR = -1} status;

Stack *create_stack();
status delete_stack(Stack *sp, void (*item_destroy)(void *));
status push(Stack *sp, void *item);
void *pop(Stack *sp);

bool stack_empty(Stack *sp);
bool stack_full(Stack *sp);
int stack_size(Stack *sp);
