#include <stdio.h>
#include "../include/cpu.h"
#include "../include/instrução.h"

int main() {
    int memoria[TAM_MEMORIA];
    int registradores[NUM_REGISTRADORES];

    inicializar_cpu(memoria, registradores);
    carregar_exemplo(memoria, registradores);

    Instrucao programa[] = {
        {1, MODO_IMEDIATO, 10, 0},       // ADD #10
        {1, MODO_DIRETO, 10, 0},         // ADD [10]
        {1, MODO_INDIRETO, 30, 0},       // ADD [[30]] => [40] => 3
        {1, MODO_REGISTRADOR, 1, 0},     // ADD R1 => 2
        {1, MODO_REG_INDIRETO, 2, 0},    // ADD [R2] => [20] => 7
        {1, MODO_INDEXADO, 10, 0},       // ADD [10 + R0] => indexado
        {1, MODO_RELATIVO, 2, 3},        // ADD [2 + R3]
        {1, MODO_BASE_INDEXADA, 4, 3}    // ADD [R3 + R4]
    };

    int num_instrucoes = sizeof(programa) / sizeof(Instrucao);

    executar_programa(programa, num_instrucoes, memoria, registradores);

    printf("\nResultado final do acumulador (registrador[0]): %d\n", registradores[0]);

    return 0;
}