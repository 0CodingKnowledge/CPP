int ocupacao() {

    char entrada_saida;
    int numero_bilhete, index;
    printf("Entrou ou Saiu? (E/S): ");
    scanf(" %c", &entrada_saida);
    if (toupper(entrada_saida) == 'E') {
        printf("Numero do bilhete?");
        scanf("%d", &numero_bilhete);
        index = pesquisarBilhete(lista, listaVIP, numero_bilhete);
        lista[index].es = 'E';
        printf("Bilhete %d registrado como entrada.\n", numero_bilhete);
        } else if (toupper(entrada_saida) == 'S') {
            printf("Numero do bilhete?");
            scanf("%d", &numero_bilhete);
            index = pesquisarBilhete(lista, listaVIP, numero_bilhete);
            lista[index].es = 'S';
            printf("Bilhete %d registrado como saída.\n", numero_bilhete);
    return EXIT_SUCCESS;
        }
}
    