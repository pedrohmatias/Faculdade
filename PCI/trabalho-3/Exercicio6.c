#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct contaBancaria
{
    int digito[10], digitoVerificador,verificador, soma; // NÃO confundir digito com verificador.
    float saldo;
    char nome[60], numeroConta[10];
};
int main(){
    struct contaBancaria *infoContas = NULL;
    struct contaBancaria *contasCorretas = NULL;
    struct contaBancaria *contasErradas = NULL;
    int i = 0, totalUsuarios = 0, tamanho = 0, peso = 0, numeroCorreto[10], totalCorretas = 0,totalErradas = 0;
    do{
        if(i >= totalUsuarios){
            totalUsuarios += 1;
            infoContas = (struct contaBancaria *) realloc(infoContas, totalUsuarios * sizeof(struct contaBancaria));
            if(infoContas == NULL){
                printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!");
                return 1;
            }
        }
        printf("informe o número da conta bancária: ");
        scanf(" %s", infoContas[i].numeroConta);
        if (infoContas[i].numeroConta[0] == '0') {
            break;
        }
        printf("informe o digito verificador: ");
        scanf("%d", &infoContas[i].verificador);
        printf("informe o saldo da conta: ");
        scanf("%f", &infoContas[i].saldo);
        printf("informe o nome do cliente: ");
        scanf("%s", infoContas[i].nome); // o scan quebra se você tenta inserir um caractere especial, em especial espaço e acento agúdo, não sei o porquê.
        infoContas[i].soma = 0;
        tamanho = strlen(infoContas[i].numeroConta);
        for(int j = 0; infoContas[i].numeroConta[j] != '\0'; j++){
            infoContas[i].digito[j] = infoContas[i].numeroConta[j] - '0';
            peso = tamanho - j;
            infoContas[i].soma += infoContas[i].digito[j] * peso;
        }
        infoContas[i].soma = infoContas[i].soma % 11;
        infoContas[i].soma = 11 - infoContas[i].soma;
        if (infoContas[i].soma == 10 || infoContas[i].soma == 11)
        {
            infoContas[i].digitoVerificador = 0;
        }else{
            infoContas[i].digitoVerificador = infoContas[i].soma;
        }
        if (infoContas[i].digitoVerificador == infoContas[i].verificador){
            totalCorretas++;
            contasCorretas = realloc(contasCorretas, totalCorretas * sizeof(struct contaBancaria));
            contasCorretas[totalCorretas - 1] = infoContas[i];
            if (contasCorretas == NULL){
                printf("Erro na realocação de contas corretas!\n");
                return 1;
            }
        }
        else{
            totalErradas++;
            contasErradas = realloc(contasErradas, totalErradas * sizeof(struct contaBancaria));
            contasErradas[totalErradas - 1] = infoContas[i];
            if (contasErradas == NULL) {
                printf("Erro na realocação de contas erradas!\n");
                return 1;
            }
        }
        i++;
    }while(infoContas[i].numeroConta[0] != '0');

    printf("CONTAS DE NÚMERO CORRETO: \n \n");
    for(i = 0; i < totalCorretas; i++){
        printf("%s     %.2f     %s  \n",contasCorretas[i].numeroConta, contasCorretas[i].saldo, contasCorretas[i].nome);
    }
    printf("CONTAS DE NÚMERO ERRADO: \n \n");
    for (i = 0; i < totalErradas; i++){
        printf("%s     %.2f     %s  \n", contasErradas[i].numeroConta, contasErradas[i].saldo, contasErradas[i].nome);
    }
    free(infoContas);
    free(contasCorretas);
    free(contasErradas);
};