#include <stdio.h>
#include <stdlib.h>
#include "../include/instrução.h"

/**
 * @brief Executa uma instrução de máquina com base nos parâmetros fornecidos.
 *
 * @param inst Instrução a ser executada.
 * @param memoria Vetor representando a memória principal.
 * @param registradores Vetor representando os registradores da CPU.
 *
 * @note O registrador[0] é utilizado como acumulador principal.
 */
void executar_instrucao(Instrucao inst, int memoria[], int registradores[]) {
    int valor = 0; /**< Valor resolvido a partir do modo de endereçamento */

    // Decodifica o modo de endereçamento e acessa o valor correspondente
    switch (inst.modo) {
        case MODO_IMEDIATO:
            valor = inst.operando;
            break;
        case MODO_DIRETO:
            valor = memoria[inst.operando];
            break;
        case MODO_INDIRETO:
            valor = memoria[memoria[inst.operando]];
            break;
        case MODO_REGISTRADOR:
            valor = registradores[inst.operando];
            break;
        case MODO_REG_INDIRETO:
            valor = memoria[registradores[inst.operando]];
            break;
        case MODO_INDEXADO:
            valor = memoria[inst.operando + registradores[0]]; // registrador[0] como indexador
            break;
        case MODO_RELATIVO:
            valor = memoria[inst.operando + inst.registrador_base];
            break;
        case MODO_BASE_INDEXADA:
            valor = memoria[registradores[inst.registrador_base] + registradores[inst.operando]];
            break;
        default:
            printf("Modo de enderecamento invalido!\n");
            return;
    }

    // Executa a operação definida pelo opcode
    switch (inst.opcode) {
        case 1: /**< ADD - Soma o valor ao acumulador (registrador[0]) */
            registradores[0] += valor;
            break;
        case 2: /**< SUB - Subtrai o valor do acumulador (registrador[0]) */
            registradores[0] -= valor;
            break;
        case 3: /**< MUL - Multiplica o valor com o acumulador (registrador[0]) */
            registradores[0] *= valor;
            break;
        case 4: /**< DIV - Divide o acumulador (registrador[0]) pelo valor */
            if (valor != 0) {
                registradores[0] /= valor;
            } else {
                printf("Erro: divisao por zero!\n");
            }
            break;
        default:
            printf("Opcode desconhecido!\n");
            break;
    }
}
