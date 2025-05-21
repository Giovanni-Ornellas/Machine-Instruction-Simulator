#ifndef INSTRUCAO_H
#define INSTRUCAO_H

/**
 * @enum ModoEnderecamento
 * @brief Define os diferentes modos de endereçamento suportados pela CPU simulada.
 */
typedef enum {
    MODO_IMEDIATO,        /**< Operando é um valor constante embutido na instrução */
    MODO_DIRETO,          /**< Operando é o endereço direto da memória */
    MODO_INDIRETO,        /**< Operando aponta para um endereço que aponta para o dado */
    MODO_REGISTRADOR,     /**< Operando está em um registrador */
    MODO_REG_INDIRETO,    /**< Endereço está contido em um registrador */
    MODO_INDEXADO,        /**< Endereço base mais valor de registrador indexador */
    MODO_RELATIVO,        /**< Endereço relativo a um registrador base */
    MODO_BASE_INDEXADA    /**< Soma de dois registradores: base e índice */
} ModoEnderecamento;

/**
 * @struct Instrucao
 * @brief Representa uma instrução de máquina com opcode, modo de endereçamento e operandos.
 */
typedef struct {
    int opcode;                    /**< Código da operação a ser executada */
    ModoEnderecamento modo;       /**< Modo de endereçamento a ser utilizado */
    int operando;                 /**< Operando ou referência ao operando */
    int registrador_base;         /**< Registrador base usado em modos relativos ou base indexada */
} Instrucao;

/**
 * @brief Executa uma instrução de máquina com base nos parâmetros fornecidos.
 *
 * @param inst Instrução a ser executada.
 * @param memoria Vetor representando a memória principal.
 * @param registradores Vetor representando os registradores da CPU.
 */
void executar_instrucao(Instrucao inst, int memoria[], int registradores[]);

#endif // INSTRUCAO_H
