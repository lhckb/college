#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node *next;
};
typedef struct Node Node;

void enqueue(Node *head, int value)
{
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->val = value;

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

void printQueue(Node *head) 
{
  for (Node *curr = head->next; curr != NULL; curr = curr->next) {
    printf("%i ", curr->val);
  }
  printf("\n");
}

void removeRecursive(Node *node, int value)
{
  if (node->next->val == value) {
    Node *trash;
    trash = node->next;
    node->next = trash->next;
    free(trash);
  }
  else {
    removeRecursive(node->next, value);
  }
}

int main()
{
  Node *first = (Node *) malloc(sizeof(Node));
  first->next = NULL;

  int qtt;
  scanf("%i", &qtt);

  int input;
  for (int i = 0; i < qtt; i++) {
    scanf("%i", &input);
    getchar();
    enqueue(first, input);
  }

  int qtt_left;
  scanf("%i", &qtt_left);

  for (int i = 0; i < qtt_left; i++) {
    scanf("%i", &input);
    getchar();
    removeRecursive(first, input);
  }

  printQueue(first);
}