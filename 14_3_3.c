#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a stack
struct stack {
  int *array;
  int size;
  int top;
};

// Function to create a stack
struct stack *createStack(int size) {
  struct stack *stack = malloc(sizeof(struct stack));
  stack->array = malloc(sizeof(int) * size);
  stack->size = size;
  stack->top = -1;
  return stack;
}

// Function to push an element to a stack
void push(struct stack *stack, int element) {
  if (stack->top == stack->size - 1) {
    printf("Stack overflow\n");
    return;
  }
  stack->top++;
  stack->array[stack->top] = element;
}

// Function to pop an element from a stack
int pop(struct stack *stack) {
  if (stack->top == -1) {
    printf("Stack underflow\n");
    return -1;
  }
  int element = stack->array[stack->top];
  stack->top--;
  return element;
}

// Function to print the elements of a stack
void printStack(struct stack *stack) {
  if (stack->top == -1) {
    printf("Stack is empty\n");
    return;
  }
  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->array[i]);
  }
  printf("\n");
}

// Function to read the data from a file of integers
void readDataFromFile(FILE *file, struct stack *stack) {
  int number;
  while (fscanf(file, "%d", &number) != EOF) {
    push(stack, number);
  }
}

// Function to print the data from a stack in reverse order
void printDataInReverseOrder(struct stack *stack) {
  while (!isEmpty(stack)) {
    printf("%d ", pop(stack));
  }
  printf("\n");
}

// Function to check if a stack is empty
int isEmpty(struct stack *stack) {
  return stack->top == -1;
}

// Main function
int main() {
  // Create a stack
  struct stack *stack = createStack(10);

  // Open the file
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the data from the file
  readDataFromFile(file, stack);

  // Print the data in reverse order
  printDataInReverseOrder(stack);

  // Close the file
  fclose(file);

  // Free the memory allocated for the stack
  free(stack);

  return 0;
}

