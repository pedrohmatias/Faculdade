#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

   struct usuario{
      char nome[50];
      int idade;
      float salario;
      bool sexo;
   };
   
int main() {
    struct usuario user;
    
    user.salario = 7840212.00;
    printf("%f",user.salario);
}
