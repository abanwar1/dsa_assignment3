#include <stdio.h>
#include <stdlib.h>

// Define the stack data structure
struct stack {
  int* data;
  int size;
  int top;
};

// Initialize the stack
void init_stack(struct stack* stack, int size) {
  stack->data = (int*)malloc(sizeof(int) * size);
  stack->size = size;
  stack->top = -1;
}

// Push an element onto the stack
void push(struct stack* stack, int element) {
  if (stack->top == stack->size - 1) {
    // Stack is full
    printf("Stack overflow\n");
    return;
  }

  stack->top++;
  stack->data[stack->top] = element;
}

// Pop an element from the stack
int pop(struct stack* stack) {
  if (stack->top == -1) {
    // Stack is empty
    printf("Stack underflow\n");
    return -1;
  }

  int element = stack->data[stack->top];
  stack->top--;
  return element;
}

// Display the contents of the stack
void display_stack(struct stack* stack) {
  if (stack->top == -1) {
    printf("Stack is empty\n");
    return;
  }

  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->data[i]);
  }

  printf("\n");
}

// Main function
int main() {
  // Create a stack with a capacity of 10 elements
  struct stack stack;
  init_stack(&stack, 10);

  // Push some elements onto the stack
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);

  // Display the contents of the stack
  display_stack(&stack);

  // Pop an element from the stack
  int element = pop(&stack);
  printf("Popped element: %d\n", element);

  // Display the contents of the stack again
  display_stack(&stack);

  return 0;
}

