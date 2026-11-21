//meow~~

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <vector>
#include <ctype.h>
#include<unistd.h>
#include<time.h>
#define N 300
#define VALOR 10
#define RAND_MAX 400

using namespace std;

class Normal {
public:
    int num;
    char es = 0;
};

class VIP {
public:
    int num;
    int nome;
    int tlm;
    char es = 0;
    char presença = 0;
};


std::vector<Normal> lista;
std::vector<VIP> listaVIP;
float preco;
float *ptr = &preco;
int vip = 0;
int codigo = 1;
int evento(int codigo) {

    while(codigo!= 1 or codigo!=2 or codigo!=3) {
        printf("Digite o código do evento (1, 2 ou 3): ");
        scanf("%d", &codigo);
    }
    if (codigo == 1) {
        printf("Evento 1 selecionado.\n");
        
    
    } else if (codigo == 3) {
        printf("Evento 3 selecionado.\n");

    }
    return EXIT_SUCCESS;
}


int inserirNormal(std::vector<Normal>& lista, float *ptr) { //resolver bug adiçao de bilhetes
    Normal bilhete;
    bilhete.num = rand() % RAND_MAX;
    lista.push_back(bilhete);
    *ptr += VALOR;
    return EXIT_SUCCESS;
}

int inserirVIP(std::vector<VIP>& listaVIP, float *ptr) {
    VIP bilhete;
    int *ptr1 = &bilhete.nome, *ptr2 = &bilhete.tlm, *ptr3 = &bilhete.num;
    bilhete.num = rand() % RAND_MAX;
    printf("Digite o nome do VIP: ");
    scanf("%d", &bilhete.nome);
    printf("Digite o número de telefone do VIP: ");
    scanf("%d", &bilhete.tlm);
    printf("%d %d %d", *ptr1, *ptr2, *ptr3);
    sleep(5);
    listaVIP.push_back(bilhete);
    *ptr += VALOR * 0.5;
    return EXIT_SUCCESS;
}

int listarBilhetes(std::vector<Normal>& lista, std::vector<VIP>& listaVIP) {
    printf("Bilhetes Normais:\n");
    for (int i = 0; i < lista.size(); i++) {
        printf("Número: %d\n", lista[i].num);
    }
    printf("Bilhetes VIP:\n");
    for (int i = 0; i < listaVIP.size(); i++) {
        printf("Número: %d, Nome: %d, TLM: %d\n", listaVIP[i].num, listaVIP[i].nome, listaVIP[i].tlm);
    }
    return EXIT_SUCCESS;
}

int pesquisarBilhete(std::vector<Normal>& lista, std::vector<VIP>& listaVIP, int numero, int vip) {
    int temp, flag= 0, i;
    printf("Digite o número do bilhete a pesquisar: ");
    scanf("%d", &temp);
    for(i = 0; i < listaVIP.size(); i++) {
            if (listaVIP[i].num == temp) {
                printf("Bilhete VIP encontrado: %d %d %d\n", listaVIP[i].num, listaVIP[i].nome, listaVIP[i].tlm);
                flag = 1;
                vip = 1;
            }
    }
    if (flag == 0) {
        for(i = 0; i < lista.size(); i++) {
            if (lista[i].num == temp) {
                printf("Bilhete Normal encontrado: %d\n", lista[i].num);
                flag = 1;
                vip = 0;
                break;
                            }
                        }    
                        
                    }      
    return i;
}
    
int sortearBilhete(std::vector<VIP>& listaVIP) {
    int numero_sorteado, flag = 0;
    numero_sorteado = rand() % RAND_MAX;
    printf("Número sorteado: %d\n", numero_sorteado);
    while(flag == 0) {
        numero_sorteado = rand() % RAND_MAX;
        printf("Número sorteado: %d\n", numero_sorteado);
        for(int i = 0; i < listaVIP.size(); i++) {
            if (listaVIP[i].num == numero_sorteado && listaVIP[i].presença == 1) {
                printf("Bilhete VIP vencedor: %d, Nome: %d, TLM: %d\n", listaVIP[i].num, listaVIP[i].nome, listaVIP[i].tlm);
                flag = 1;
                break;
            }
        }
    }
    return EXIT_SUCCESS;
}


int ocupacao() {
    char entrada_saida;
    int numero_bilhete, index;
    printf("Entrou ou Saiu? (E/S): ");
    scanf(" %c", &entrada_saida);
    if (toupper(entrada_saida) == 'E') {
        printf("Numero do bilhete?");
        scanf("%d", &numero_bilhete);
        index = pesquisarBilhete(lista, listaVIP, numero_bilhete, vip);
        lista[index].es = 'E';
        if (vip == 1) {
            listaVIP[index].es = 'E';
            listaVIP[index].presença = 1;
        } else if (vip == 0) {
            lista[index].es = 'E';
        }
        printf("Bilhete %d registrado como entrada.\n", numero_bilhete);
        } else if (toupper(entrada_saida) == 'S') {
            printf("Numero do bilhete?");
            scanf("%d", &numero_bilhete);
            index = pesquisarBilhete(lista, listaVIP, numero_bilhete, vip);
            if (vip == 0) {
                lista[index].es = 'S';
            } else if (vip == 1) {
                listaVIP[index].es = 'S';
            }
            printf("Bilhete %d registrado como saída.\n", numero_bilhete);
        }
    return EXIT_SUCCESS;
} 


int consultar_ocupacao() {
    int counter = 0;
    for(int i = 0; i < lista.size(); i++) {
        if (lista[i].es == 'E') {
            printf("Bilhete Normal %d está dentro do evento.\n", lista[i].num);
            counter++;
        } else if (lista[i].es == 'S') {
            printf("Bilhete Normal %d saiu do evento.\n", lista[i].num);
        }
    }
    for(int i = 0; i < listaVIP.size(); i++) {
        if (listaVIP[i].es == 'E') {
            printf("Bilhete VIP %d está dentro do evento.\n", listaVIP[i].num);
            counter++;
        } else if (listaVIP[i].es == 'S') {
            printf("Bilhete VIP %d saiu do evento.\n", listaVIP[i].num);
        }
    }
    printf("Lugares disponíveis: %d\n", N - counter);
    printf("Percentagem de ocupação: %.2f%%\n", (float)counter / N * 100);
    sleep(5);
    return EXIT_SUCCESS;
}

int menu(){
    while(true) {
    system("clear");
    printf("1 - Inserir bilhete\n");
    printf("2 - Listar bilhetes\n");
    printf("3 - Pesquisar bilhete\n");
    printf("4 - Sortear bilhete\n");
    printf("5 - Sair\n");
    printf("6 - Registrar Entrada/Saída\n");
        int opt;
        printf("Escolha uma opção: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
            if (lista.size() + listaVIP.size() >= N) {
                printf("Limite de bilhetes atingido.\n");
                sleep(5);
                break;
            }
            char temp;
            printf("VIP? Y/N");
            scanf(" %c", &temp);
            if (toupper(temp) == 'Y') {
                inserirVIP(listaVIP, ptr);
                break;

            } else {
                inserirNormal(lista, ptr);
                break;
                }
                
        
            case 2: {
                listarBilhetes(lista, listaVIP);
                sleep(5);
                break;
                }
            
            case 3: {
                    pesquisarBilhete(lista, listaVIP, 0, vip);
                    sleep(5);
                    break;
                }
            case 4:{
                    sortearBilhete(listaVIP);
                    sleep(5);
                    break;
                       }
            case 5:
                       printf("Saindo...\n");
                       return EXIT_SUCCESS;

            case 6: {
                ocupacao();
                break;
                    }
            default:
                printf("Opção inválida.\n");
                sleep(5);
                break;
            }    
           
                    }
                }
            
                

        
int main(void){
    menu();

    exit(EXIT_SUCCESS);
}


