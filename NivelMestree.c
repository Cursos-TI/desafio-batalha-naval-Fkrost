#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define HAB 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

void aplicarHabilidade(int tabuleiro[TAM][TAM], int hab[HAB][HAB], int origemX, int origemY);

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- Posicionando navios ---
    tabuleiro[1][2] = NAVIO; tabuleiro[1][3] = NAVIO; tabuleiro[1][4] = NAVIO;
    tabuleiro[5][4] = NAVIO; tabuleiro[6][4] = NAVIO; tabuleiro[7][4] = NAVIO;
    tabuleiro[0][0] = NAVIO; tabuleiro[1][1] = NAVIO; tabuleiro[2][2] = NAVIO;
    tabuleiro[7][9] = NAVIO; tabuleiro[8][8] = NAVIO; tabuleiro[9][7] = NAVIO;

    // --- Matrizes de habilidades ---
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // CONE (triângulo apontando para baixo)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (j >= (HAB/2 - i) && j <= (HAB/2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // CRUZ
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == HAB/2 || j == HAB/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // OCTAEDRO (losango)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (abs(i - HAB/2) + abs(j - HAB/2) <= HAB/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Aplicando habilidades
    aplicarHabilidade(tabuleiro, cone, 2, 5);
    aplicarHabilidade(tabuleiro, cruz, 6, 2);
    aplicarHabilidade(tabuleiro, octaedro, 5, 7);

    // --- Exibindo o tabuleiro exatamente como na imagem ---
    printf("  ");
    for (int j = 0; j < TAM; j++) printf("%d", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i); // índice da linha
        for (int j = 0; j < TAM; j++) {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Função para aplicar as habilidades no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int hab[HAB][HAB], int origemX, int origemY) {
    int offset = HAB / 2;
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (hab[i][j] == 1) {
                int x = origemX + (i - offset);
                int y = origemY + (j - offset);
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == AGUA)
                        tabuleiro[x][y] = HABILIDADE;
                }
            }
        }
    }
}
