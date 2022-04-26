#include <stdio.h>

// estrutura basica
typedef struct Produto {
  char nome[30];
  int codigo;
  int quantidade_disponível;
  int num_vendas;
  int num_compras;
  float preco;
  int status;

  struct Produto *next;
  struct Produto *prev;
};
typedef struct Produto Produto;

// operações...
void inserir();

// geração de relatórios...

int main()
{
  int cond = 1;

  Produto *head = (Produto *) malloc(sizeof(Produto));
  head->next = NULL;
  head->prev = NULL; 

  int choice;
  do {
    printf("1- inserir\n2- remover\n3- buscar\n4- comprar\n5- vender\n6- lista dos mais vendidos\n7- produtos mais comprados\n8- extrato da conta\n9- produtos em estoque\n");
    scanf("%i", &choice);

    switch (choice) {
      case 1:

    }

  } while (cond);

  return 0;
}