#include <stdio.h>
#include <string.h>

int main()
{
  float idade, codigo, quantidade, preco = 0;
  char bebida[20];
  int escolha;

  printf("diga sua idade: ");
  scanf("%f", &idade);

  if (idade < 18) {
    printf("voce nao pode comprar bebidas\n");
  }
  else {
    printf("1- whisky; 2- vodka; 3- cerveja; 4- cachaça\n");
    scanf("%i", &escolha);

    switch (escolha) {
      case 1:
        printf("cod. 100 | whisky 1 | R$200\n");
        printf("cod. 101 | whisky 2 | R$150\n");
        printf("cod. 102 | whisky 3 | R$140\n");

        printf("diga o código da bebida: ");
        scanf("%f", &codigo);

        if (codigo == 100) {
          strcpy(bebida, "whisky 1");
          preco = 200;
        }
        else if (codigo == 101) {
          strcpy(bebida, "whisky 2");
          preco = 150;
        }
        else if (codigo == 102) {
          strcpy(bebida, "whisky 3");
          preco = 140;
        }

        printf("diga a quantidade: ");
        scanf("%f", &quantidade);

        if (quantidade < 1) {
          printf("quantidade inválida\n");
        }
        else if (quantidade < 6) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade));
        }
        else if (quantidade < 51) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.9);
        }
        else if (quantidade < 101) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.7);
        }
        else {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.65);

        }

        break;


      case 2:
        printf("cod. 200 | vodka 1 | R$60\n");
        printf("cod. 201 | vodka 2 | R$40\n");
        printf("cod. 202 | vodka 3 | R$30\n");

        printf("diga o código da bebida: ");
        scanf("%f", &codigo);

        if (codigo == 200) {
          strcpy(bebida, "vodka 3");
          preco = 60;
        }
        else if (codigo == 201) {
          strcpy(bebida, "vodka 3");
          preco = 40;
        }
        else if (codigo == 202) {
          strcpy(bebida, "vodka 3");
          preco = 30;
        }

        printf("diga a quantidade: ");
        scanf("%f", &quantidade);

        if (quantidade < 1) {
          printf("quantidade inválida\n");
        }
        else if (quantidade < 6) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade));
        }
        else if (quantidade < 51) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.9);
        }
        else if (quantidade < 101) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.7);
        }
        else {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.65);

        }

        break;


      case 3:
        printf("cod. 300 | cerveja 1 | R$1.5\n");
        printf("cod. 301 | cerveja 2 | R$2\n");
        printf("cod. 302 | cerveja 3 | R$3\n");

        printf("diga o código da bebida: ");
        scanf("%f", &codigo);

        if (codigo == 300) {
          strcpy(bebida, "cerveja 3");
          preco = 1.5;
        }
        else if (codigo == 301) {
          strcpy(bebida, "cerveja 3");
          preco = 2;
        }
        else if (codigo == 302) {
          strcpy(bebida, "cerveja 3");
          preco = 3;
        }

        printf("diga a quantidade: ");
        scanf("%f", &quantidade);

        if (quantidade < 1) {
          printf("quantidade inválida\n");
        }
        else if (quantidade < 6) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade));
        }
        else if (quantidade < 51) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.9);
        }
        else if (quantidade < 101) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.7);
        }
        else {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.65);

        }

        break;


      case 4:
        printf("cod. 400 | cachaça 1 | R$8\n");
        printf("cod. 401 | cachaça 2 | R$20\n");
        printf("cod. 402 | cachaça 3 | R$22\n");

        printf("diga o código da bebida: ");
        scanf("%f", &codigo);

        if (codigo == 400) {
          strcpy(bebida, "cachaça 3");
          preco = 8;
        }
        else if (codigo == 401) {
          strcpy(bebida, "cachaça 3");
          preco = 20;
        }
        else if (codigo == 402) {
          strcpy(bebida, "cachaça 3");
          preco = 22;
        }

        printf("diga a quantidade: ");
        scanf("%f", &quantidade);

        if (quantidade < 1) {
          printf("quantidade inválida\n");
        }
        else if (quantidade < 6) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade));
        }
        else if (quantidade < 51) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.9);
        }
        else if (quantidade < 101) {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.7);
        }
        else {
          printf("sua bebida %s com %.0f unidade(s) deu %.2f reais\n", bebida, quantidade, (preco * quantidade) * 0.65);

        }

        break;

      default:
        printf("opçao inválida\n");
        break;
    }
  }

  return 0;
}