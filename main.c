// Versionado em https://github.com/JoaozinhoDrgnBr/Posto-de-Gasolina.git

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct tipocarro *fcarro, *atendidos;

int main(void) {
  float preco, armaz = 0, vend = 0, i;
  // i=para armazenar quantos litros serão abastecidos em um carro
  // j=usado como contador para whiles
  int fila, carro = 0, flag, flag3, atend = 0, j;
  // flags = escolhas para menus

  printf("Programa por: João Otávio Bazzo Zimermann\n");
  printf("Este programa foi criado com o proposito de gerenciar um posto de "
         "gasolina\nhipotetico\n\n");

  printf("Informe o valor do combustivel:\n");
  scanf("%f", &preco);
  printf("Informe o tamanho da fila suportada:\n");
  scanf("%d", &fila);
  fcarro = calloc(fila, sizeof(struct tipocarro));
  atendidos = calloc(1, sizeof(struct tipocarro));
  printf("Informe a quantidade de combustivel armazenado:\n");
  scanf("%f", &armaz);

  while (flag != 6) {
    i=0;
    printf("\e[1;1H\e[2J");
    // system("clear");
    printf(WHT
           "\nSelecione a opção:\n1. Adicionar carro a fila\n2. Abastecer\n3. "
           "Exibir fila de espera\n4. Relatórios\n5. Adicionar combustivel\n6. Encerrar\n");
    scanf("%d", &flag);
    printf("\n");

    switch (flag) {
    case 1:
      if (carro < fila) {
        carro = carro + 1;

        flush_in();
        printf(WHT "Informe a marca do carro:\n");
        fgets(fcarro[carro - 1].marca, 15, stdin);
        printf("Informe o modelo do carro:\n");
        fgets(fcarro[carro - 1].modelo, 15, stdin);
        printf("Informe o ano do carro:\n");
        scanf("%d", &fcarro[carro - 1].ano);
        printf(GRN "Carro adicionado\n");

      } else {
        printf(RED "A fila está em capacidade máxima\n");
      }

      break;
    case 2:
      if (armaz <= 0) {
        printf("Não há mais combustivel nas bombas, carros serão liberados\n");
        carro = 0;
      } else if (carro > 0) {
        printf("Informe quanto combustivel será abastecido:\n");
        scanf("%f", &i);
        if (i > armaz) {
          flag3=0;
          printf("\nCombustivel informado excede ao restante na bomba: "
                 "%.3f\nDeseja abastecer com o restante?\n" GRN "1. Sim\n" RED "2. Não\n" WHT,
                 armaz);
          scanf("%d", &flag3);
          switch (flag3){
            case 1:
              vend = vend+armaz;
              armaz = 0;
              --carro;
          atendidos = (struct tipocarro *)realloc(
              atendidos, (atend + 1) * sizeof(struct tipocarro));
          strcpy(atendidos[atend].marca, fcarro[0].marca);
          strcpy(atendidos[atend].modelo, fcarro[0].modelo);
          atendidos[atend].ano = fcarro[0].ano;
          atend++;
          j = 0;
          while (j < carro) {
            strcpy(fcarro[j].marca, fcarro[j + 1].marca);
            strcpy(fcarro[j].modelo, fcarro[j + 1].modelo);
            fcarro[j].ano = fcarro[j + 1].ano;
            j++;
          }
              printf(GRN "Carro abastecido\n" WHT);
            break;
            case 2:
              printf(RED"Carro foi liberado sem ser abastecido\n" WHT);
              --carro;
          j = 0;
          while (j < carro) {
            strcpy(fcarro[j].marca, fcarro[j + 1].marca);
            strcpy(fcarro[j].modelo, fcarro[j + 1].modelo);
            fcarro[j].ano = fcarro[j + 1].ano;
            j++;
            }
            break;
            default:
              printf(YEL"instrução inválida, voltando ao menu...\n" WHT);
            break;
          }
           
        } else {
          --carro;
          atendidos = (struct tipocarro *)realloc(
              atendidos, (atend + 1) * sizeof(struct tipocarro));
          strcpy(atendidos[atend].marca, fcarro[0].marca);
          strcpy(atendidos[atend].modelo, fcarro[0].modelo);
          atendidos[atend].ano = fcarro[0].ano;
          atend++;
          j = 0;
          while (j < carro) {
            strcpy(fcarro[j].marca, fcarro[j + 1].marca);
            strcpy(fcarro[j].modelo, fcarro[j + 1].modelo);
            fcarro[j].ano = fcarro[j + 1].ano;
            j++;
          }
          armaz = armaz - i;
          vend = vend + i;
          printf(GRN "Carro abastecido\n" WHT);
        }
      } else {
        printf(RED "Não há carros para abastecer" WHT);
      }
      break;
    case 3:
      j = 0;
      printf("A quantidade de carros na fila é de: %d\n\n", carro);
      while (j < carro) {
        printf("%s%s%d\n\n", fcarro[j].marca, fcarro[j].modelo, fcarro[j].ano);
        j++;
      }
      break;
    case 4:
      fmenu2(vend, preco, atend, atendidos, armaz);
      break;
    case 6:
      printf(YEL "Encerrando...");
      exit(0);
      break;
    case 5:
      printf("Quanto combustivel deseja adicionar?");
      scanf("%f", &i);
      armaz=armaz+i;
    default:
      printf(RED "Intrução inválida\n");
      break;
    }
    printf(WHT "\nPressione qualquer tecla para continuar:");
    getchar();
    getchar();
  }

  return 0;
}