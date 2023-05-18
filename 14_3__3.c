#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 10

struct stack {
  int *data;
  int top;
  int size;
};

struct multi_stack {
  struct stack stacks[MAX_STACKS];
  int n_stacks;
};

void init_multi_stack(struct multi_stack *ms, int n_stacks) {
  ms->n_stacks = n_stacks;
  for (int i = 0; i < n_stacks; i++) {
    ms->stacks[i].data = malloc(sizeof(int) * MAX_STACKS);
    ms->stacks[i].top = -1;
    ms->stacks[i].size = MAX_STACKS;
  }
}

void push(struct multi_stack *ms, int stack_id, int item) {
  if (ms->stacks[stack_id].top == ms->stacks[stack_id].size - 1) {
    printf("Stack overflow\n");
    exit(1);
  }
  ms->stacks[stack_id].data[++ms->stacks[stack_id].top] = item;
}

int pop(struct multi_stack *ms, int stack_id) {
  if (ms->stacks[stack_id].top == -1) {
    printf("Stack underflow\n");
    exit(1);
  }
  int item = ms->stacks[stack_id].data[ms->stacks[stack_id].top--];
  return item;
}

int peek(struct multi_stack *ms, int stack_id) {
  if (ms->stacks[stack_id].top == -1) {
    printf("Stack underflow\n");
    exit(1);
  }
  return ms->stacks[stack_id].data[ms->stacks[stack_id].top];
}

int main() {
  struct multi_stack ms;
  init_multi_stack(&ms, 3);
  push(&ms, 0, 1);
  push(&ms, 1, 2);
  push(&ms, 2, 3);
  printf("Top of stack 0: %d\n", peek(&ms, 0));
  printf("Top of stack 1: %d\n", peek(&ms, 1));
  printf("Top of stack 2: %d\n", peek(&ms, 2));
  int item = pop(&ms, 2);
  printf("Popped from stack 2: %d\n", item);
  return 0;
}
