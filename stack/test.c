#include "stack.h"
#include "../support/item.h"
#include "../tester/tester.h"

int main(void)
{
    printf("Testing a stack...\n");

    Stack *s;

    s = create_stack();
    assert("can create stack",
            s != NULL);
    assert("can push one element", 
            push(s, new_item(1)) == OK);
    assert("stack size increased to 1",
            stack_size(s) == 1);
    assert("can pop on element",
            ((Item *) pop(s))->foo == 1);
    assert("stack size decreased to 0",
            stack_size(s) == 0);
    assert("can delete stack",
            delete_stack(s) == OK);

    return 0;
}
