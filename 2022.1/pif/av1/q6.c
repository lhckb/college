#include <stdio.h>
#include <stdlib.h>

float saldo_padaria = 0;

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

Produto* buscar(Produto *head, int codigo)
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
  // printf("\n\n");

  for (Produto *curr = head->next; curr != NULL; curr = curr->next) {
    printf("nome: %s\n", curr->nome);
    printf("codigo: %i\n", curr->codigo);
    printf("quantidade disponivel: %i\n", curr->quantidade_disponivel);
    printf("num compras: %i\n", curr->num_compras);
    printf("num vendas: %i\n", curr->num_vendas);
    printf("preço: R$%.2f\n", curr->preco);
    printf("\n");
  }

  printf("\n\n");
}

void printProduto(Produto *produto)
{
  printf("nome: %s\n", produto->nome);
  printf("codigo: %i\n", produto->codigo);
  printf("quantidade disponivel: %i\n", produto->quantidade_disponivel);
  printf("num compras: %i\n", produto->num_compras);
  printf("num vendas: %i\n", produto->num_vendas);
  printf("preço: R$%.2f\n", produto->preco);
}

int obterTamanhoLista(Produto *head)
{
  int count = 0;
  for (Produto *curr = head->next; curr != NULL; curr = curr->next) {
    count++;
  }

  return count;
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
    printf("NÃO PODE TER DOIS PRODUTOS COM O MESMO CÓDIGO!!!\n");
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
    saldo_padaria -= produto->preco * qtd;

    return 1;
  }

  return 0;
}
int vender(Produto *head, int codigo)
{
  Produto *produto = buscar(head, codigo);
  int count = produto->num_vendas;
  if (produto) {
    int qtd;
    printf("quantas unidades vender? ");
    scanf("%i", &qtd);

    if (qtd > produto->quantidade_disponivel) {
      printf("NÃO É POSSÍVEL VENDER QUANTIDADE SUPERIOR AO ESTOQUE!!!\n");
      return 0;
    }

    count++;
    produto->num_vendas = count;
    produto->quantidade_disponivel -= qtd;
    saldo_padaria += produto->preco * qtd;

    return 1;
  }

  return 0;
}

// geração de relatórios...
void listaMaisVendidos(Produto *head)
{
  int size = obterTamanhoLista(head);

  for (int i = 0; i < size - 1; i++) {
    for (Produto *curr = head->next; curr->next != NULL; curr = curr->next) {
      if (curr->num_vendas < curr->next->num_vendas) {
        Produto *prox_atual = curr->next;
        Produto *ant_atual = curr->prev;

        ant_atual->next = prox_atual; 
        prox_atual->prev = ant_atual;

        curr->prev = prox_atual;
        curr->next = prox_atual->next; 
        prox_atual->next = curr;  
      }
    }
  }

  printf("\n-----PRODUTOS MAIS VENDIDOS-----\n");
  printProdutos(head);
}
void listaMaisComprados(); 

void extratoPadaria()
{
  printf("a padaria tem R$%.2f no banco\n", saldo_padaria);
}

void listaProdutosEstoque(Produto *head)
{
  printf("\n-----PRODUTOS EM ESTOQUE-----\n");
  for (Produto *curr = head->next; curr != NULL; curr = curr->next) {
    if (curr->quantidade_disponivel > 0) {
      printProduto(curr);
    }
  }
}

int main()
{
  int cond = 1;
  
  Produto *head = (Produto *) malloc(sizeof(Produto));
  head->next = NULL;
  head->prev = NULL;

  int choice;
  do {
    printProdutos(head);

    printf("1- inserir\n2- remover\n3- buscar\n4- comprar\n5- vender\n6- lista dos mais vendidos\n7- lista dos mais comprados\n8- extrato da conta\n9- produtos em estoque\n");
    scanf("%i", &choice);

    int codigo;
    switch (choice) {
      case 1:
        inserir(head);
        break;

      case 2:
        printf("codigo do produto a remover: ");
        scanf("%i", &codigo);

        remover(head, codigo);
        break;

      case 3:
        printf("codigo do produto a buscar: ");
        scanf("%i", &codigo);

        Produto *busca = buscar(head, codigo);
        printf("\n-----PRODUTO BUSCADO-----\n");
        printProduto(busca);
        break;

      case 4: 
        printf("codigo do produto a comprar: ");
        scanf("%i", &codigo);

        comprar(head, codigo);
        break;

      case 5:
        printf("codigo do produto a vender: ");
        scanf("%i", &codigo);

        vender(head, codigo);
        break;

      case 6:
        listaMaisVendidos(head);
        break;

      case 8:
        extratoPadaria();
        break;

      case 9:
        listaProdutosEstoque(head);
        break;

      default:
        cond = 0;
        break;
    }

  } while (cond);

  return 0;
}