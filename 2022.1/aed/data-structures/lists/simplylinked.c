#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

typedef struct Node node;


void printLinkedList(node *list) 
{
  printf("\n");

  for (node *curr = list->next; curr != NULL; curr = curr->next) {
    printf(" %i |", curr->value);
  }
  printf("\n\n");
}

void insertNodeToEnd(node *firstNode) 
{
  int val;
  printf("type in the int value: ");
  scanf("%i", &val);

  node *newNode = (node *) malloc(sizeof(node));
  newNode->value = val;

  if (firstNode->next == NULL) {
    firstNode->next = newNode;
    newNode->next = NULL;
  }
  else {
    for (node *curr = firstNode->next; curr != NULL; curr = curr->next) {
      if (curr->next == NULL) {
        curr->next = newNode;
        newNode->next = NULL;
      }
    }
  }
}

void insertNodeToBeginning(node *firstNode)
{
  int val;
  printf("type in the value for this new node: ");
  scanf("%i", &val);

  node *newNode = (node *) malloc(sizeof(node));
  newNode->value = val;
  newNode->next = firstNode->next;
  firstNode->next = newNode;
}

void removeNode(node *list)
{
  int val;
  printf("type in the value to remove: ");
  scanf("%i", &val);

  for (node *curr = list; curr != NULL; curr = curr->next) {
    node *nextItem = (node *) malloc(sizeof(node));
    nextItem = curr->next;

    if (nextItem->value == val) {
      curr->next = nextItem->next;
      free(nextItem);
    }
  }
}

void freeAll(node *first)
{
  node *curr = first;
  node *next;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  free(curr);
  free(next);
}

node* searchItem(node *first)
{
  int val, count;
  node *res;
  printf("type in the value to search: ");
  scanf("%i", &val);

  for (node *curr = first; curr != NULL; curr = curr->next) {
    if (curr->value == val) {
      count++;
      res = curr;
    }
  }

  if (count == 0) {
    printf("node not found\n");
  }
  else {
    printf("node value is %i and points to %i\n", res->value, res->next->value);
  }
}

void insertionSort();

int main()
{
  int cond = 1;

  node *firstNode = (node *) malloc(sizeof(node));
  firstNode->next = NULL;

  int choice;
  do {
    printf("1- print list\n2- insert node to end of list\n3- remove given node\n4- insert element in beginning of list\n5- search for node\n");
    scanf("%i", &choice);

    switch (choice) {
      case 1:
        printLinkedList(firstNode);
        break;

      case 2:
        insertNodeToEnd(firstNode);
        break;

      case 3: ;
        removeNode(firstNode);
        break;

      case 4: ;
        insertNodeToBeginning(firstNode);
        break;

      case 5: 
        searchItem(firstNode);
        break;

      // implementar ordenação (insertion sort)

      default:
        cond = 0;
        break;
    }

  } while (cond);

  freeAll(firstNode);

  return 0;
}