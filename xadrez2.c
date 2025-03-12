#include <stdio.h> // Biblioteca padrão para entrada e saída

// Definição de constantes para facilitar manutenção e evitar valores fixos
#define MOVIMENTO_BISPO 5
#define MOVIMENTO_TORRE 5
#define MOVIMENTO_RAINHA 8

int main() {
    int i; // Variável de controle para os loops

    // ==========================
    // Movimentação do Bispo
    // ==========================
    printf("\n=== Movimentação do Bispo ===\n");
    i = 0;
    while (i < MOVIMENTO_BISPO) { // Loop WHILE para movimentação do bispo
        printf("Movimento %d: Cima + Direita\n", i + 1);
        i++;
    }

    // ==========================
    // Movimentação da Torre
    // ==========================
    printf("\n=== Movimentação da Torre ===\n");
    for (i = 0; i < MOVIMENTO_TORRE; i++) { // Loop FOR para movimentação da torre
        printf("Movimento %d: Direita\n", i + 1);
    }

    // ==========================
    // Movimentação da Rainha
    // ==========================
    printf("\n=== Movimentação da Rainha ===\n");
    i = 0;
    do { // Loop DO-WHILE para movimentação da rainha
        printf("Movimento %d: Esquerda\n", i + 1);
        i++;
    } while (i < MOVIMENTO_RAINHA);

    // ==========================
    // Fim do programa
    // ==========================
    printf("\nMovimentações concluídas com sucesso!\n");

    return 0;
}
