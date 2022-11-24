#include <stdio.h>
#include <stdlib.h>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

FILE *fp = NULL;

struct tipocarro {
  int ano;
  char marca[20], modelo[20];
};

void fmenu2(float vend, float preco, int atend, struct tipocarro atendidos[],
            float armaz) {
  int flag2 = 0, j;
  while (flag2 != 6) {
    printf("\e[1;1H\e[2J");
    printf(WHT
           "\nInforme a opção:\n1. Quantidade de litros vendida\n2. Valor "
           "arrecadado\n3. Quantidade "
           "de carros abastecidos\n4. Quantidade de combustivel restante\n5. "
           "Gerar arquivo para impressão\n6. Voltar ao menu anterior\n");
    scanf("%d", &flag2);
    printf("\n");
    switch (flag2) {
    case 1:
      printf("%.2f litros foram vendidos\n", vend);
      break;
    case 2:
      printf("R$%.2f foram arrecadados\n", vend * preco);
      break;
    case 3:
      j = 0;
      printf("%d carros foram abastecidos\n\n", atend);
      while (j < atend) {
        printf("%s%s%d\n\n", atendidos[j].marca, atendidos[j].modelo,
               atendidos[j].ano);
        j++;
      }
      break;
    case 4:
      printf("%.2f de combustivel restam no tanque\n", armaz);
      break;
    case 5:
      fp = fopen("registro.txt", "w");

      fprintf(fp, "Registro de atividades:\n\n");
      fprintf(fp, "%.2f litros foram vendidos\n", vend);
      fprintf(fp, "R$%.2f foram arrecadados\n", vend * preco);
      fprintf(fp, "%.2f de combustivel restam no tanque\n", armaz);
      fprintf(fp, "%d carros foram abastecidos\n\n", atend);
      j = 0;
      while (j < atend) {
        fprintf(fp, "%s%s%d\n\n", atendidos[j].marca, atendidos[j].modelo,
                atendidos[j].ano);
        j++;
      }
      fclose(fp);

      printf(YEL "Arquivo sendo gerado...\n\n");
      printf(GRN "Arquivo gerado com sucesso!\n");

      break;
    case 6:
      printf(YEL "Voltando...\n");
      break;
    default:
      printf(RED "Opção inválida\n");
      break;
    }
    printf(WHT "\nPressione qualquer tecla para continuar:");
    getchar();
    getchar();
  }
}