#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node *next;
};
typedef struct Node Node;

struct Stack {
  Node *top;
  Node *base;
};
typedef struct Stack Stack;

void printMin(Stack *stack)
{
  int min = stack->top->val;

  if (!stack->base->val && !stack->top->val) {
    printf("EMPTY\n");
  }
  else {
    for (Node *curr = stack->top; curr->next != NULL; curr = curr->next) {
      if (curr->val < min) {
        min = curr->val;
      }
    }

    printf("%i\n", min);
  }
}

void push(Stack *stack, Node *head, int newVal)
{
  Node *newNode = (Node *) malloc(sizeof(Node));

  newNode->val = newVal;

  newNode->next = stack->top;
  stack->top = newNode;
}

void pop(Stack *stack)
{
  Node *top = stack->top;
  stack->top = top->next;
  free(top);
}
 
int main() {
 
  Stack *stack = (Stack *) malloc(sizeof(Stack));
  Node *head = (Node *) malloc(sizeof(Node));

  stack->base = head;
  stack->top = head;

  int qtt;
  scanf("%i", &qtt);

  long int num;
  char input[5];
  for (int i = 0; i < qtt; i++) {
    scanf("%s", input);
    getchar();

    if (input[0] == 'P' && input[1] == 'U') {
      scanf(" %li", &num);
      push(stack, head, num);
    }
    else if (input[0] == 'P' && input[1] == 'O') {
      pop(stack);
    }
    else {
      printMin(stack);
    }
  }

  free(stack);
  free(head);
 
  return 0;
}