#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};
typedef struct Node Node;

void freeAll(Node *first)
{
  Node *curr = first;
  Node *next;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  free(curr);
  free(next);
}

void printQueue(Node *head) 
{
  printf("\n");

  for (Node *curr = head->next; curr != NULL; curr = curr->next) {
    printf(" %i |", curr->value);
  }
  printf("\n\n");
}

void enqueue(Node *head)
{
  int val;
  printf("new value: ");
  scanf("%i", &val);

  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->value = val;

  if (head->next == NULL) {
    head->next = newNode;
    newNode->next = NULL;
  }
  else {
    for (Node *curr = head->next; curr != NULL; curr = curr->next) {
      if (curr->next == NULL) {
        curr->next = newNode;
        newNode->next = NULL;
      }
    }
  }
}

void dequeue(Node *head)
{
  if (head->next != NULL) {
    Node *first = head->next;
    head->next = first->next;
    free(first);
  }
}

int main()
{
  int cond = 1;

  Node *head = (Node *) malloc(sizeof(Node));
  head->next = NULL;

  int choice;
  do {
    printf("1- print queue\n2- enqueue\n3- dequeue\n");
    scanf("%i", &choice);

    switch (choice) {
      case 1:
        printQueue(head);
        break;

      case 2:
        enqueue(head);
        break;

      case 3:
        dequeue(head);
        break;

      default:
        cond = 0;
        break;
    }

  } while (cond);

  freeAll(head);

  return 0;
}
