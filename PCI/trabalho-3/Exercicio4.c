#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct voo{
    int numeroVoo, tipoAviao, numeroLugares, totalLugares;
    float precoPassagem;
};

struct reserva{
    char identidade[100];
    int numeroVoo;
};

int main() {
    struct voo infoVoos[10];
    struct reserva *passageiros = NULL;
    int i = 0, j = 0,capacidade = 0;
    for ( i = 0; i < 10; i++){
        printf("Informe o número do vôo: ");
        scanf("%d", &infoVoos[i].numeroVoo);
        printf("Informe o tipo do avião: ");
        scanf("%d", &infoVoos[i].tipoAviao);     
        printf("Informe o preço da passagem: ");
        scanf("%f", &infoVoos[i].precoPassagem);

        switch (infoVoos[i].tipoAviao)
        {
        case 707:
            infoVoos[i].numeroLugares = 200;
            infoVoos[i].totalLugares = 200;
            break;
        case 727:
            infoVoos[i].numeroLugares = 170;
            infoVoos[i].totalLugares = 170;
            break;
        case 737:
            infoVoos[i].numeroLugares = 120;
            infoVoos[i].totalLugares = 120;
            break;
        default:
            break;
        }  
    }
    do {
        if (j >= capacidade) {
            capacidade += 1;
            passageiros = (struct reserva *)realloc(passageiros, capacidade * sizeof(struct reserva));
            if (passageiros == NULL) {
                printf("Erro na alocação de memória!\n");
                return 1;
            }
        }
        printf("Digite a identidade do passageiro: ");
        scanf("%s", passageiros[j].identidade);
        if (strcmp(passageiros[j].identidade, "0") != 0) {
            printf("Digite o número do voo: ");
            scanf("%d", &passageiros[j].numeroVoo);
            for (int k = 0; k < 10; k++) {
                if (passageiros[j].numeroVoo == infoVoos[k].numeroVoo) {
                    if (infoVoos[k].numeroLugares > 0) {
                        infoVoos[k].numeroLugares -= 1;
                        printf("NUMERO DA IDENTIDADE: %s\n", passageiros[j].identidade);
                        printf("NUMERO DO VÔO: %d\n", passageiros[j].numeroVoo);
                        printf("PREÇO DA PASSAGEM: %.2f\n", infoVoos[k].precoPassagem);
                        printf("PASSAGEM CONFIRMADA\n");
                    } else {
                        printf("VÔO LOTADO\n");
                    }
                }
            }
            j++;
        } else {
            break; 
        }
    } while (1);
    for(i=0;i<10;i++){
        if(infoVoos[i].numeroLugares == infoVoos[i].totalLugares * 0.60){
            printf("O VÔO  %d NÃO DEU LUCROS NEM PREJUIZOS \n", i);
        } else if (infoVoos[i].numeroLugares < infoVoos[i].totalLugares * 0.60)
        {
            printf("O VÔO  %d DEU LUCROS \n", i);
        }else if (infoVoos[i].numeroLugares > infoVoos[i].totalLugares * 0.60)
        {
            printf("O VÔO %d DEU PREJUIZOS \n", i);
        }
    }
    free(passageiros);
}