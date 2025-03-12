#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h> // Para a função sleep()

#define TAMANHO_TABULEIRO 8
#define BISPO_MOV 5
#define TORRE_MOV 5
#define RAINHA_MOV 8

// Função para exibir o tabuleiro
void mostrarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n   0 1 2 3 4 5 6 7\n");
    printf("  -----------------\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d| ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '.'; // Posições vazias representadas por '.'
        }
    }
}

// Função para movimentar a peça mostrando o andamento
void movimentarPeca(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int *linha, int *coluna, int movimentos, char direcao) {
    // Remove a peça da posição inicial
    tabuleiro[*linha][*coluna] = '.';

    for (int i = 0; i < movimentos; i++) {
        // Faz a movimentação da peça
        switch (direcao) {
            case 'W': // Cima
                if (*linha > 0) (*linha)--; // Evita mover para fora do tabuleiro
                break;
            case 'S': // Baixo
                if (*linha < TAMANHO_TABULEIRO - 1) (*linha)++;
                break;
            case 'A': // Esquerda
                if (*coluna > 0) (*coluna)--; // Evita mover para fora do tabuleiro
                break;
            case 'D': // Direita
                if (*coluna < TAMANHO_TABULEIRO - 1) (*coluna)++;
                break;
            case 'E': // Diagonal superior direita (para o Bispo)
                if (*linha > 0 && *coluna < TAMANHO_TABULEIRO - 1) {
                    (*linha)--;
                    (*coluna)++;
                }
                break;
            default:
                printf("Direção inválida!\n");
                return;
        }

        // Marca o caminho percorrido com '*'
        tabuleiro[*linha][*coluna] = '*';

        // Exibe o tabuleiro após cada movimento
        mostrarTabuleiro(tabuleiro);
        sleep(1); // Aguarda 1 segundo para mostrar o movimento em tempo real
    }

    // Marca a posição final da peça
    tabuleiro[*linha][*coluna] = 'P';
    mostrarTabuleiro(tabuleiro);
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha = 4, coluna = 4; // Posição inicial da peça
    int opcao, movimentos;
    char direcao;

    inicializarTabuleiro(tabuleiro);
    tabuleiro[linha][coluna] = 'P'; // A peça começa na posição central

    do {
        mostrarTabuleiro(tabuleiro);

        // Seleção da peça com validação de entrada
        do {
            printf("\nEscolha a peça:\n");
            printf("1 - Bispo\n");
            printf("2 - Torre\n");
            printf("3 - Rainha\n");
            printf("4 - Sair\n");
            printf("Opção: ");
            if (scanf("%d", &opcao) != 1) {
                while (getchar() != '\n'); // Limpa o buffer
                printf("Entrada inválida! Tente novamente.\n");
                opcao = 0;
            }
        } while (opcao < 1 || opcao > 4);

        if (opcao == 4) {
            printf("\nJogo encerrado! Obrigado por jogar.\n");
            break;
        }

        // Define o número de movimentos com base na peça
        switch (opcao) {
            case 1:
                movimentos = BISPO_MOV;
                printf("\nVocê escolheu o Bispo! Ele pode se mover na diagonal.\n");
                break;
            case 2:
                movimentos = TORRE_MOV;
                printf("\nVocê escolheu a Torre! Ela pode se mover para os lados.\n");
                break;
            case 3:
                movimentos = RAINHA_MOV;
                printf("\nVocê escolheu a Rainha! Ela pode se mover em qualquer direção.\n");
                break;
        }

        // Entrada da direção
        do {
            printf("\nDigite a direção (W = Cima, S = Baixo, A = Esquerda, D = Direita");
            if (opcao == 1) {
                printf(", E = Diagonal Superior Direita");
            }
            printf("): ");
            scanf(" %c", &direcao);
            direcao = toupper(direcao); // Garante que a direção será sempre maiúscula

            if (direcao != 'W' && direcao != 'S' && direcao != 'A' && direcao != 'D' &&
                !(direcao == 'E' && opcao == 1)) {
                printf("Direção inválida! Tente novamente.\n");
            }
        } while (direcao != 'W' && direcao != 'S' && direcao != 'A' && direcao != 'D' &&
                 !(direcao == 'E' && opcao == 1));

        // Movimentação da peça com exibição do caminho
        movimentarPeca(tabuleiro, &linha, &coluna, movimentos, direcao);

    } while (1);

    return 0;
}
