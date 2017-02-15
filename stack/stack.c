#include "stack.h"

#define TOP_EMPTY -1
#define MALLOC_BUFFER 2

struct _Stack {
  void **data;
  int top;
  int capacity;
};

Stack *create_stack()
{
  Stack *sp = NULL;
  sp = (Stack *) malloc(sizeof(Stack));
  if (!sp)
    return NULL;

  sp->top = TOP_EMPTY;

  sp->data = malloc(MALLOC_BUFFER * sizeof(void *));
  sp->capacity = MALLOC_BUFFER;
  if (!sp->data)
    return NULL;

  return sp;
}

status delete_stack(Stack *sp, void (*item_destroy)(void *))
{
  if (!sp)
    return ERROR;

  for (int i = 0; i < stack_size(sp); i++)
      item_destroy(sp->data[i]);

  free(sp->data);
  sp->data = NULL;
  return OK;
}

status push(Stack *sp, void *item, void *(*item_copy)(void *))
{
  if (!sp || !item)
    return ERROR;

  // grow as necessary
  if (stack_full(sp))
  {
    void **new_data = realloc(sp->data, (sp->capacity + MALLOC_BUFFER) * sizeof(void *));
    if (new_data)
    {
      sp->data = new_data;
      sp->capacity += MALLOC_BUFFER;
    }
    else
      return ERROR;
  }

  sp->top++;
  sp->data[sp->top] = item_copy(item);

  return OK;
}

void *pop(Stack *sp)
{
  if (!sp)
    return NULL;

  if (stack_empty(sp))
    return NULL;

  sp->top--;
  return sp->data[sp->top + 1];
}

bool stack_empty(Stack *sp)
{
  return sp->top < 0;
}

bool stack_full(Stack *sp)
{
  return sp->top >= sp->capacity - 1;
}

int stack_size(Stack *sp)
{
  return sp->top + 1;
}
