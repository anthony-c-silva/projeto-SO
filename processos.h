#ifndef PROCESSOS_H
#define PROCESSOS_H

#include "memoria.h" 


typedef struct {
    int pid; // Identificador do processo
    int estado; // Estado do processo (por exemplo, pronto, em execução, etc.)
    
} Processo;


void init_processos();

// Salva o estado do processador na entrada correspondente ao processo em execução
void salvar_estado(Processo *processo);

// Recupera o estado do processador a partir da tabela para o processo em execução
void recuperar_estado(Processo *processo);

// Função escalonador que escolhe o próximo processo a ser executado
void escalonador();

// Função para tratar interrupções e pendências
void tratador_interrupcao();

// Chamada para criar um novo processo
int criar_processo();

// Chamada para encerrar um processo
void encerrar_processo(int pid);

// Altera as chamadas de E/S para usar um terminal diferente dependendo do pid do processo
void realizar_entrada_saida(int pid);

#endif
