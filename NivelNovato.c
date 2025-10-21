#include <stdio.h>

int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];
    printf(" TABULEIRO BATALHA NAVAL \n");
    // Inicializa o tabuleiro com 0 (vazio)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- NAVIO 1 (HORIZONTAL) ---
    int navio1[3] = {3, 3, 3};
    int linhaNavio1 = 2; // linha 2 (índice 1)
    int colunaInicial1 = 4; // coluna E (índice 4)

    // Posiciona navio 1 horizontalmente
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavio1][colunaInicial1 + i] = navio1[i];
    }

    // --- NAVIO 2 (VERTICAL) ---
    int navio2[3] = {3, 3, 3};
    int linhaInicial2 = 5; // linha 6 (índice 5)
    int colunaNavio2 = 7; // coluna H (índice 7)

    // Verifica se o navio 2 não sobrepõe o 1
    int sobrepoe = 0;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaInicial2 + i][colunaNavio2] != 0) {
            sobrepoe = 1;
        }
    }

    if (!sobrepoe) {
        // Posiciona navio 2 verticalmente
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaInicial2 + i][colunaNavio2] = navio2[i];
        }
    } else {
        printf("Erro: navios sobrepostos!\n");
    }

    // --- IMPRIMINDO TABULEIRO ---
    printf("\n   ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
