#include <stdio.h>

long long factorial(int n){
    long long result = 1;
    if(n == 0 || n == 1){
    
        return 1;    
    }
   else{
     result = n*factorial(n-1);
   }
   return result;
}

int main(){
    int n;
    
   if(scanf("%d", &n) != 1){ 
        printf("Erro na leitura do valor\n");
        return 1;
    }

      if(n<0){
        printf("outro valor\n");
        return 0;
    }

    long long resultado = factorial(n);

    printf("%lld\n", resultado);


    return 0;
}