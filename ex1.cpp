#include <stdio.h>



int main(){

    int hs,ms,ss,hc,mc,sc,dh,dm,ds;
    
    printf("Hora de Saida: ");
    scanf("%d",&hs);
    printf("Minuto de Saida: ");
    scanf("%d",&ms);
    printf("Segundo de Saida: ");
    scanf("%d",&ss);

    printf("Hora de Chegada: ");
    scanf("%d",&hc);
    printf("Minuto de Chegada: ");
    scanf("%d",&mc);
    printf("Segundo de Chegada: ");
    scanf("%d",&sc);

    dh = hc - hs;
    dm = mc - ms;
    ds = sc - ss;

    printf("Tempo de viagem: %d:%d:%d", dh, dm, ds);

    return 0;


}
