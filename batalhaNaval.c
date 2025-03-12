#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio horizontal ou verticalmente
int posicionarNavioHorizontalVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Fora do tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] == 3) return 0; // Sobreposição
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else { // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Fora do tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == 3) return 0; // Sobreposição
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
    return 1;
}

// Função para posicionar um navio na diagonal
int posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    if (direcao == 0) { // Diagonal crescente (ex: tabuleiro[i][i])
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0; // Fora do tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna + i] == 3) return 0; // Sobreposição
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = 3;
        }
    } else { // Diagonal decrescente (ex: tabuleiro[i][9-i])
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) return 0; // Fora do tabuleiro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna - i] == 3) return 0; // Sobreposição
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Posicionando navios (coordenadas e orientação definidas diretamente)
    if (!posicionarNavioHorizontalVertical(tabuleiro, 2, 3, 0)) printf("Erro ao posicionar navio 1\n"); // Navio horizontal
    if (!posicionarNavioHorizontalVertical(tabuleiro, 5, 1, 1)) printf("Erro ao posicionar navio 2\n"); // Navio vertical
    if (!posicionarNavioDiagonal(tabuleiro, 1, 1, 0)) printf("Erro ao posicionar navio 3\n"); // Navio diagonal crescente
    if (!posicionarNavioDiagonal(tabuleiro, 1, 8, 1)) printf("Erro ao posicionar navio 4\n"); // Navio diagonal decrescente

    exibirTabuleiro(tabuleiro);

    return 0;
}