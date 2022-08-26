#include <stdio.h>
#include <stdlib.h>

#define limite 1000

float saldo_padaria = 0;
int qtd_produtos = 0;

// estrutura basica
struct Produto{
  char nome[30];
  int codigo;
  int quantidade_disponivel;
  int num_vendas;
  int num_compras;
  float preco;
  int status;
};
typedef struct Produto Produto;

int buscar(Produto lista[], int codigo)
{
  for (int i = 0; i < qtd_produtos; i++) {
    if (lista[i].codigo == codigo) {
      return i;
    }
  }

  return -1;
}

void printProdutos(Produto lista[]) 
{
  for (int i = 0; i< qtd_produtos; i++) {
    printf("nome: %s\n", lista[i].nome);
    printf("codigo: %i\n", lista[i].codigo);
    printf("quantidade disponivel: %i\n", lista[i].quantidade_disponivel);
    printf("num compras: %i\n", lista[i].num_compras);
    printf("num vendas: %i\n", lista[i].num_vendas);
    printf("preço: R$%.2f\n", lista[i].preco);
    printf("\n");
  }

  printf("\n\n");
}

void printProduto(Produto produto)
{
  printf("nome: %s\n", produto.nome);
  printf("codigo: %i\n", produto.codigo);
  printf("quantidade disponivel: %i\n", produto.quantidade_disponivel);
  printf("num compras: %i\n", produto.num_compras);
  printf("num vendas: %i\n", produto.num_vendas);
  printf("preço: R$%.2f\n", produto.preco);
}

// operações...
int inserir(Produto lista[])
{
  Produto newProduct;

  printf("nome do produto: ");
  scanf(" %[^\n]", newProduct.nome);
  printf("código do produto: ");
  scanf("%i", &newProduct.codigo);

  int check = buscar(lista, newProduct.codigo);

  if (lista[check].codigo == newProduct.codigo) {
    printf("NÃO PODE TER DOIS PRODUTOS COM O MESMO CÓDIGO!!!\n");
    return 0;
  }

  printf("preço do produto: ");
  scanf("%f", &newProduct.preco);

  newProduct.quantidade_disponivel = 0;
  newProduct.num_compras = 0;
  newProduct.num_vendas = 0;
  newProduct.status = 1;

  lista[qtd_produtos] = newProduct;
  qtd_produtos++;

  return 1;
} 

int remover(Produto lista[], int codigo)
{
  int check = buscar(lista, codigo);
  
  if (lista[check].codigo == codigo) {
    for (int i = check; i < qtd_produtos; i++) {
      lista[i] = lista[i+1];
    }

    qtd_produtos--;
  }
}

int comprar(Produto lista[], int codigo)
{
  int check = buscar(lista, codigo);
  if (check != -1) {
    int qtd;
    printf("quantas unidades comprar? ");
    scanf("%i", &qtd);

    lista[check].num_compras++;
    lista[check].quantidade_disponivel += qtd;
    saldo_padaria -= lista[check].preco * qtd;

    return 1;
  }

  return 0;
}

int vender(Produto lista[], int codigo)
{
  int check = buscar(lista, codigo);
  if (check != -1) {
    int qtd;
    printf("quantas unidades vender? ");
    scanf("%i", &qtd);

    if (qtd > lista[check].quantidade_disponivel) {
      printf("NÃO É POSSÍVEL VENDER QUANTIDADE SUPERIOR AO ESTOQUE!!!\n");
      return 0;
    }

    lista[check].num_vendas++;
    lista[check].quantidade_disponivel -= qtd;
    saldo_padaria += lista[check].preco * qtd;

    return 1;
  }

  return 0;
}

// geração de relatórios...
void listaMaisVendidos(Produto lista[])
{
  for (int i = 0; i < qtd_produtos - 1; i++) {
    for (int j = 0; j < qtd_produtos - 1; j++) {
      if (lista[j].num_vendas < lista[j + 1].num_vendas) {
        Produto temp = lista[j];
        lista[j] = lista[j + 1];
        lista[j + 1] = temp;
      }
    }
  }

  printf("\n-----PRODUTOS MAIS VENDIDOS-----\n");
  printProdutos(lista);
}

void listaMaisComprados(Produto lista[])
{
  for (int i = 0; i < qtd_produtos - 1; i++) {
    for (int j = 0; j < qtd_produtos - 1; j++) {
      if (lista[j].num_compras < lista[j + 1].num_compras) {
        Produto temp = lista[j];
        lista[j] = lista[j + 1];
        lista[j + 1] = temp;
      }
    }
  }

  printf("\n-----PRODUTOS MAIS COMPRADOS-----\n");
  printProdutos(lista);
} 

void extratoPadaria()
{
  printf("a padaria tem R$%.2f no banco\n", saldo_padaria);
}

void listaProdutosEstoque(Produto lista[])
{
  printf("\n-----PRODUTOS EM ESTOQUE-----\n");
  for (int i = 0; i < qtd_produtos; i++) {
    if (lista[i].quantidade_disponivel > 0) {
      printProduto(lista[i]);
    }
  }
}

int main()
{
  int cond = 1;
  Produto produtos[limite];

  int choice;
  do {
    printf("1- inserir\n2- remover\n3- buscar\n4- comprar\n5- vender\n6- lista dos mais vendidos\n7- lista dos mais comprados\n8- extrato da conta\n9- produtos em estoque\n10- listar todos os produtos\n");
    scanf("%i", &choice);

    int codigo;
    switch (choice) {
      case 1:
        inserir(produtos);
        break;

      case 2:
        printf("codigo do produto a remover: ");
        scanf("%i", &codigo);

        remover(produtos, codigo);
        break;

      case 3:
        printf("codigo do produto a buscar: ");
        scanf("%i", &codigo);

        int check = buscar(produtos, codigo);
        printf("\n-----PRODUTO BUSCADO-----\n");
        printProduto(produtos[check]);
        break;

      case 4: 
        printf("codigo do produto a comprar: ");
        scanf("%i", &codigo);

        comprar(produtos, codigo);
        break;

      case 5:
        printf("codigo do produto a vender: ");
        scanf("%i", &codigo);

        vender(produtos, codigo);
        break;

      case 6:
        listaMaisVendidos(produtos);
        break;

      case 7:
        listaMaisComprados(produtos);
        break;

      case 8:
        extratoPadaria();
        break;

      case 9:
        listaProdutosEstoque(produtos);
        break;

      case 10:
        printProdutos(produtos);
        break;

      default:
        cond = 0;
        break;
    }

  } while (cond);

  return 0;
}