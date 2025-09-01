#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro (10x10)
#define NAVIO 3       // Valor que representa navio no tabuleiro
#define AGUA 0        // Valor que representa água
#define TAM_NAVIO 3   // Comprimento fixo dos navios

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para imprimir o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para validar se o navio cabe no tabuleiro
int validarPosicao(int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // 0 = horizontal
        return (coluna + TAM_NAVIO <= TAM);
    } else { // 1 = vertical
        return (linha + TAM_NAVIO <= TAM);
    }
}

// Função para verificar sobreposição com outro navio
int verificarSobreposicao(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // horizontal
        for (int j = 0; j < TAM_NAVIO; j++) {
            if (tabuleiro[linha][coluna + j] == NAVIO) {
                return 0; // Sobreposição encontrada
            }
        }
    } else { // vertical
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                return 0; // Sobreposição encontrada
            }
        }
    }
    return 1; // Sem sobreposição
}

// Função para posicionar um navio
int posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao) {
    if (!validarPosicao(linha, coluna, orientacao)) {
        printf("ERRO: Navio nao cabe no tabuleiro nessa posicao!\n");
        return 0;
    }
    if (!verificarSobreposicao(tabuleiro, linha, coluna, orientacao)) {
        printf("ERRO: Navio se sobrepoe a outro!\n");
        return 0;
    }

    // Preenche a matriz com o valor NAVIO (3)
    if (orientacao == 0) { // horizontal
        for (int j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linha][coluna + j] = NAVIO;
        }
    } else { // vertical
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    return 1;
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Define coordenadas fixas para os navios
    int linhaNavio1 = 2, colunaNavio1 = 1; // Navio horizontal
    int linhaNavio2 = 5, colunaNavio2 = 4; // Navio vertical

    // Posiciona os dois navios
    if (posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 0)) {
        printf("Navio 1 (Horizontal) posicionado com sucesso!\n");
    }
    if (posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 1)) {
        printf("Navio 2 (Vertical) posicionado com sucesso!\n");
    }

    // Exibe o tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}
