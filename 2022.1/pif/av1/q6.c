#include <stdio.h>
#include <stdlib.h>

int padaria = 0;

// estrutura basica
struct Produto{
  char nome[30];
  int codigo;
  int quantidade_disponivel;
  int num_vendas;
  int num_compras;
  float preco;
  int status;

  struct Produto *next;
  struct Produto *prev;
};
typedef struct Produto Produto;

Produto *buscar(Produto *head, int codigo)
{
  for (Produto *curr = head->next; curr != NULL; curr = curr->next) {
    if (curr->codigo == codigo) {
      return curr;
    }
  }

  return NULL;
}

void printProdutos(Produto *head) 
{
  printf("\n\n");

  for (Produto *curr = head->next; curr != NULL; curr = curr->next) {
    printf("nome: %s\n", curr->nome);
    printf("codigo: %i\n", curr->codigo);
    printf("quantidade disponivel: %i\n", curr->quantidade_disponivel);
    printf("num compras: %i\n", curr->num_compras);
    printf("num vendas: %i\n", curr->num_vendas);
    printf("preço: %f\n", curr->preco);
  }

  printf("\n\n");
}

// operações...
int inserir(Produto *head)
{
  Produto *newProduct = (Produto *) malloc(sizeof(Produto));

  printf("nome do produto: ");
  scanf(" %[^\n]", newProduct->nome);
  printf("código do produto: ");
  scanf("%i", &newProduct->codigo);

  if (buscar(head, newProduct->codigo)) {
    free(newProduct);
    return 0;
  }

  printf("preço do produto: ");
  scanf("%f", &newProduct->preco);

  newProduct->quantidade_disponivel = 0;
  newProduct->num_compras = 0;
  newProduct->num_vendas = 0;
  newProduct->status = 1;

  if (head->next == NULL) {
    head->next = newProduct;
    newProduct->next = NULL;
    newProduct->prev = head;
  }
  else if (head->next->next == NULL) {
    head->next->next = newProduct;
    newProduct->next = NULL;
    newProduct->prev = head->next;
  }
  else {
    for (Produto *curr = head->next; curr != NULL; curr = curr->next) {
      if (curr->next->next == NULL) {
        curr->next->next = newProduct;
        newProduct->next == NULL;
        newProduct->prev = curr->next;
        
        return 1;
      }
    } 
  }
} 

int remover(Produto *head, int codigo)
{
  Produto *produto = buscar(head, codigo);
  if (!produto) {
    return 0;
  }
  else {
    produto->prev->next = produto->next;
    free(produto);
    return 1;
  }
}

int comprar(Produto *head, int codigo)
{
  Produto *produto = buscar(head, codigo);
  if (produto) {
    int qtd;
    printf("quantas unidades comprar? ");
    scanf("%i", &qtd);

    produto->num_compras ++;
    produto->quantidade_disponivel += qtd;
    padaria -= produto->preco * qtd;

    return 1;
  }

  return 0;
}
int vender(Produto *head, int codigo)
{
  Produto *produto = buscar(head, codigo);
  if (produto) {
    int qtd;
    printf("quantas unidades vender? ");
    scanf("%i", &qtd);

    produto->num_vendas ++;
    produto->quantidade_disponivel -= qtd;
    padaria += produto->preco * qtd;

    return 1;
  }

  return 0;
}

// geração de relatórios...
void listaMaisVendidos();
void listaMaisComprados();
void extratoPadaria();
void listaProdutosEstoque();

int main()
{
  int cond = 1;
  
  Produto *head = (Produto *) malloc(sizeof(Produto));
  head->next = NULL;
  head->prev = NULL;

  int choice;
  do {
    printProdutos(head);

    printf("1- inserir\n2- remover\n3- buscar\n4- comprar\n5- vender\n6- lista dos mais vendidos\n7- produtos mais comprados\n8- extrato da conta\n9- produtos em estoque\n");
    scanf("%i", &choice);

    switch (choice) {

    }

  } while (cond);

  return 0;
}