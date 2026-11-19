#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 300
#define VALOR 10

struct bilhetes{
    int num;
    char nome[100];
    int tlm;
};

struct bilhetes {
    int num;
    char nome[100];
    int tlm;
};

struct bilhetes lista[N];

int menu(){
    printf("1 - Inserir bilhete\n");
    printf("2 - Listar bilhetes\n");
    printf("3 - Pesquisar bilhete\n");
    printf("4 - Sair\n");
    while(true) {
        int opt;
        printf("Escolha uma opção: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                // Inserir bilhete
                break;
            case 2: {
                int i =0;
                 while((i<N)&& bilhetes[i].num != 0) {
                    printf("Bilhete %d: %s, %d\n", bilhetes[i].num, bilhetes[i].nome, bilhetes[i].tlm);
                    i++;
                }
                break;
            }
            case 3:
                // Pesquisar bilhete
                break;
            case 4:
                printf("Saindo...\n");
                return EXIT_SUCCESS;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
        exit(0);
        
    }
}

int main(){
 

    return EXIT_SUCCESS;
}