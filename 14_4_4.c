#include <stdio.h>
#include <stdbool.h>


// Assuming the stack implementation is already defined

bool areStacksEqual(Stack* stack1, Stack* stack2) {
    // Check if the sizes of the stacks are equal
    if (stackSize(stack1) != stackSize(stack2)) {
        return false;
    }

    // Create temporary stacks to preserve the original stacks
    Stack* temp1 = createStack();
    Stack* temp2 = createStack();

    bool equal = true;

    // Compare the elements of both stacks
    while (!isEmpty(stack1)) {
        // Check if the corresponding elements in both stacks are equal
        if (top(stack1) != top(stack2)) {
            equal = false;
            break;
        }

        // Move elements from the original stacks to the temporary stacks
        push(temp1, pop(stack1));
        push(temp2, pop(stack2));
    }

    // Restore the original stacks from the temporary stacks
    while (!isEmpty(temp1)) {
        push(stack1, pop(temp1));
        push(stack2, pop(temp2));
    }

    // Free the temporary stacks
    destroyStack(temp1);
    destroyStack(temp2);

    return equal;
}

