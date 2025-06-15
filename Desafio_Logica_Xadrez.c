#include <stdio.h>

#define PASSOS_TORRE 3
#define PASSOS_BISPO 3
#define PASSOS_RAINHA 2
#define LINHAS_TABULEIRO 8
#define COLUNAS_TABULEIRO 8

// ---------- MOVIMENTOS COM RECURSIVIDADE ----------

// Torre: movimenta-se na vertical e horizontal
void moverTorreCima(int passos) {
    if (passos == 0) return;
    printf("Cima\n");
    moverTorreCima(passos - 1);
}

void moverTorreBaixo(int passos) {
    if (passos == 0) return;
    printf("Baixo\n");
    moverTorreBaixo(passos - 1);
}

void moverTorreEsquerda(int passos) {
    if (passos == 0) return;
    printf("Esquerda\n");
    moverTorreEsquerda(passos - 1);
}

void moverTorreDireita(int passos) {
    if (passos == 0) return;
    printf("Direita\n");
    moverTorreDireita(passos - 1);
}

// Bispo: movimenta-se na diagonal (recursivo)
void moverBispoDiagonalDireitaCima(int passos) {
    if (passos == 0) return;
    printf("Diagonal Direita-Cima\n");
    moverBispoDiagonalDireitaCima(passos - 1);
}

void moverBispoDiagonalEsquerdaBaixo(int passos) {
    if (passos == 0) return;
    printf("Diagonal Esquerda-Baixo\n");
    moverBispoDiagonalEsquerdaBaixo(passos - 1);
}

// Rainha: combina torre + bispo
void moverRainha(int passos) {
    if (passos == 0) return;

    printf("Movimento Rainha - Cima\n");
    moverTorreCima(1);

    printf("Movimento Rainha - Diagonal Direita-Cima\n");
    moverBispoDiagonalDireitaCima(1);

    moverRainha(passos - 1);
}

// ---------- LOOPS COMPLEXOS - CAVALO ----------

void moverCavalo() {
    printf("\nMovimentos do Cavalo (em L - duas casas para cima e uma para direita):\n");

    for (int i = 0; i < LINHAS_TABULEIRO; i++) {
        for (int j = 0; j < COLUNAS_TABULEIRO; j++) {
            int novaLinha = i - 2;
            int novaColuna = j + 1;

            if (novaLinha < 0 || novaColuna >= COLUNAS_TABULEIRO) {
                continue;
            }

            printf("Cavalo move de (%d,%d) para (%d,%d): ", i, j, novaLinha, novaColuna);
            printf("Duas casas para cima, uma para direita\n");

            // Para mostrar controle de fluxo:
            if ((i + j) % 5 == 0) break;
        }
    }
}

// ---------- LOOPS ANINHADOS - BISPO ----------

void moverBispoComLoops() {
    printf("\nMovimentos do Bispo com Loops Aninhados (Diagonal):\n");

    for (int i = 1; i <= PASSOS_BISPO; i++) {
        for (int j = 1; j <= PASSOS_BISPO; j++) {
            if (i == j) {
                printf("Bispo move Diagonal para (%d,%d)\n", i, j);
            }
        }
    }
}

// ---------- MAIN ----------

int main() {
    printf("Movimentos da Torre (recursivo):\n");
    moverTorreCima(PASSOS_TORRE);
    moverTorreBaixo(PASSOS_TORRE);
    moverTorreEsquerda(PASSOS_TORRE);
    moverTorreDireita(PASSOS_TORRE);

    printf("\nMovimentos do Bispo (recursivo):\n");
    moverBispoDiagonalDireitaCima(PASSOS_BISPO);
    moverBispoDiagonalEsquerdaBaixo(PASSOS_BISPO);

    moverBispoComLoops(); // loops aninhados bispo

    printf("\nMovimentos da Rainha (recursivo):\n");
    moverRainha(PASSOS_RAINHA);

    moverCavalo(); // loops complexos cavalo

    return 0;
}
