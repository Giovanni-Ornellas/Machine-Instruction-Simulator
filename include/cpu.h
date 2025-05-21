#ifndef CPU_H
#define CPU_H

#include "../include/instrução.h"

#define TAM_MEMORIA 256
#define NUM_REGISTRADORES 8

/**
 * @brief Inicializa a memória e os registradores com valores padrão.
 *
 * @param memoria Vetor representando a memória principal.
 * @param registradores Vetor representando os registradores.
 */
void inicializar_cpu(int memoria[], int registradores[]);

/**
 * @brief Carrega valores de teste na memória e registradores para simulação.
 *
 * @param memoria Vetor representando a memória principal.
 * @param registradores Vetor representando os registradores.
 */
void carregar_exemplo(int memoria[], int registradores[]);

/**
 * @brief Executa um conjunto de instruções.
 *
 * @param instrucoes Vetor de instruções.
 * @param num_instrucoes Quantidade de instruções no vetor.
 * @param memoria Vetor representando a memória principal.
 * @param registradores Vetor representando os registradores.
 */
void executar_programa(Instrucao instrucoes[], int num_instrucoes, int memoria[], int registradores[]);

#endif // CPU_H