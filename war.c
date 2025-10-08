#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes Globais
#define MAX_TERRITORIO 5

//Definição da estrutura Territorio
struct Territorio{
    char nome[30];
    char cor[10];
    int tropas;
};

//Limpador de Buffer de entrada
void limpaBufferEntrada(){
    int c;
    while((c=getchar()) != '\n' && c!= EOF);
}

//Função principal
int main(){
    // estrutura vetor MAPA com territorio como elemento.
    struct Territorio mapa [MAX_TERRITORIO];
    printf("========================================\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");

    // Cadastro dos Territorios (Nome, Cor e quantidade de tropas)
    for (int i =0; i<MAX_TERRITORIO; i++){
        printf("--- Cadastrando territorio %d ---\n", i+1);
        printf("Nome do Territorio: \n");
        fgets(mapa[i].nome, 30, stdin);
        printf("Cor do Exercito (ex: Azul, Verde..): \n");
        fgets(mapa[i].cor, 10, stdin);

        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Numero de Tropas: \n");
        scanf("%d", &mapa[i].tropas);

        limpaBufferEntrada();
    }
    printf("\n===================================\n");

    // Impressão na tela de cada Territorio cadastrado.
    for (int i=0; i<5; i++){
        printf("TERRITORIO: %d\n", i+1);
        printf("   - Nome: %s\n", mapa[i].nome);
        printf("   - Dominado por: Exército %s\n",mapa[i].cor);
        printf("   - Número de Tropas: %d\n", mapa[i].tropas);
    }

return 0;
}