#include <stdio.h>

int main() {
    // Número de casas que cada peça deve percorrer
    int movimentoTorre = 5;
    int movimentoBispo = 5;
    int movimentoRainha = 8;

    // -------------------------------
    // Torre: usa "for"
    // Movimento: 5 casas para a direita
    // -------------------------------
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= movimentoTorre; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // -------------------------------
    // Bispo: usa "while"
    // Movimento: 5 casas para cima e para a direita (diagonal)
    // -------------------------------
    printf("Movimento do Bispo:\n");
    int contadorBispo = 1;
    while (contadorBispo <= movimentoBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }
    printf("\n");

    // -------------------------------
    // Rainha: usa "do-while"
    // Movimento: 8 casas para a esquerda
    // -------------------------------
    printf("Movimento da Rainha:\n");
    int contadorRainha = 1;
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= movimentoRainha);

    return 0;
}
