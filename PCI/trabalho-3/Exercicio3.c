#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

struct ficha{
   char nome[60];
   int inscricao,classe;
   float horasNormais,horasExtras;
};
struct contracheque{
    char nome[60];
    int inscricao,classe;
    float salarioHorasExtras, salarioHorasNormais, deducaoInss, salarioLiquido, salarioBruto;
};
int main() {
     struct ficha fichas[3];
     struct contracheque contraCheques[3];
     float salarioReferencia;
     printf("Informe o Salário de referência:");
     scanf("%f", &salarioReferencia);
    for (int i = 0; i < 3; i++){
        printf("Inscrição: ");
        scanf("%d", &fichas[i].inscricao);
        printf("Nome: ");
        scanf("%59s", fichas[i].nome);
        printf("Classe: ");
        scanf("%d", &fichas[i].classe);
        printf("Horas normais: ");
        scanf("%f", &fichas[i].horasNormais);
        printf("Horas extras: ");
        scanf("%f", &fichas[i].horasExtras);
    }
    for (int i = 0; i < 3; i++){
        for (int i = 0; i < 3; i++) {
            int j;
            for (j = 0; fichas[i].nome[j] != '\0'; j++) {
                contraCheques[i].nome[j] = fichas[i].nome[j];
            }
        }
        contraCheques[i].inscricao = fichas[i].inscricao;
        contraCheques[i].classe = fichas[i].classe;
        if (contraCheques[i].classe == 1){
            contraCheques[i].salarioHorasNormais = salarioReferencia * 1.3;
        }
        else{
            contraCheques[i].salarioHorasNormais = salarioReferencia * 1.9;
        }
        contraCheques[i].salarioHorasExtras = contraCheques[i].salarioHorasNormais * 1.3;
        contraCheques[i].salarioBruto = (contraCheques[i].salarioHorasNormais * fichas[i].horasNormais) + (contraCheques[i].salarioHorasExtras * fichas[i].horasExtras);
        contraCheques[i].deducaoInss = contraCheques[i].salarioBruto * 0.08;
        contraCheques[i].salarioLiquido = contraCheques[i].salarioBruto - contraCheques[i].deducaoInss;
        printf("CONTRACHEQUE: \n");
        printf("NUMERO DE INSCRIÇÃO: %d \n",contraCheques[i].inscricao);
        printf("NOME: %s \n", contraCheques[i].nome);
        printf("SALARIO HORAS NORMAIS: %.2f \n",(contraCheques[i].salarioHorasNormais * fichas[i].horasNormais));
        printf("SALARIO HORAS EXTRA: %.2f \n",(contraCheques[i].salarioHorasExtras * fichas[i].horasExtras));
        printf("DEDUÇÃO INSS: %.2f \n",contraCheques[i].deducaoInss);
        printf("SALARIO LÍQUIDO: %.2f \n",contraCheques[i].salarioLiquido);
    }
}