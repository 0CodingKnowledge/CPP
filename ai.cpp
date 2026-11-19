#include <stdio.h>

int main(){
   int n, original_n, soma = 0; // Inicializamos a soma a 0
   
   printf("enter a number: ");
   scanf("%d", &n);
   
   original_n = n; // Guardamos o valor original para usar no print final
   
   while(n > 0){
      soma += n;   // Acumula o valor atual à soma (soma = soma + n)
      n--;         // Decrementa n para avançar no ciclo
   }

   printf("the sum of the numbers from 1 to %d is: %d\n", original_n, soma);
     
   return 0;
}