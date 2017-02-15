/**
 * A poor stack implementation by Elias Hernandis.
 *
 * 20170202
 */

/* #include <stdio.h> // necessary? (because of NULL) */
#include <stdlib.h>
#include <stdbool.h>

typedef enum {OK = 0, ERROR = -1} status;

/*
 * A dynamically alocated, growable but not shrinkable stack implementation
 * that can store generic elements via void * pointers.
 */
typedef struct _Stack Stack;

/*
 * Returns a pointer to a Stack, NULL on failure.
 */
Stack *create_stack();

/*
 * Frees the stack pointed to by sp.
 * item_destroy must be a pointer to a function that frees the elements inside
 * the stack.
 */
status delete_stack(Stack *sp, void item_destroy(void *));

/*
 * Inserts an item atop the stack.
 * Requires a pointer to a function able
 * to copy the item being stored.
 */
status push(Stack *sp, void *item, void *item_copy(void *));

/*
 * Returns the item atop the stack and removes it from the stack.
 */
void *pop(Stack *sp);

/*
 * True if there are no elements on the stack.
 */
bool stack_empty(Stack *sp);

/*
 * True if the stack is full (more elements can still be added if we're able to
 * resize the stack).
 */
bool stack_full(Stack *sp);

/*
 * Returns the number of elements stored on the stack.
 */
int stack_size(Stack *sp);
