#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

struct tipocarro {
  int ano;
  char marca[20], modelo[20];
};

void fmenu2(float vend, float preco, int atend, struct tipocarro atendidos[],
            float armaz);