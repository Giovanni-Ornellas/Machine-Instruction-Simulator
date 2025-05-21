#include <stdio.h>
#include <string.h>
#include "../include/instrução.h"

#define TAM_MEMORIA 256
#define NUM_REGISTRADORES 8

/**
 * @brief Inicializa a memória e os registradores com valores padrão.
 *
 * @param memoria Vetor representando a memória principal.
 * @param registradores Vetor representando os registradores.
 */
void inicializar_cpu(int memoria[], int registradores[]) {
    memset(memoria, 0, sizeof(int) * TAM_MEMORIA);
    memset(registradores, 0, sizeof(int) * NUM_REGISTRADORES);
}

/**
 * @brief Carrega valores de teste na memória e registradores para simulação.
 *
 * @param memoria Vetor representando a memória principal.
 * @param registradores Vetor representando os registradores.
 */
void carregar_exemplo(int memoria[], int registradores[]) {
    memoria[10] = 5;
    memoria[20] = 7;
    memoria[30] = 40; // indireto
    memoria[40] = 3;

    registradores[1] = 2;  // para registrador direto
    registradores[2] = 20; // para indireto
    registradores[3] = 1;  // base
    registradores[4] = 1;  // índice
    registradores[0] = 0;  // acumulador
}

/**
 * @brief Executa um conjunto de instruções.
 *
 * @param instrucoes Vetor de instruções.
 * @param num_instrucoes Quantidade de instruções no vetor.
 * @param memoria Vetor representando a memória principal.
 * @param registradores Vetor representando os registradores.
 */
void executar_programa(Instrucao instrucoes[], int num_instrucoes, int memoria[], int registradores[]) {
    for (int i = 0; i < num_instrucoes; ++i) {
        executar_instrucao(instrucoes[i], memoria, registradores);
    }
}
