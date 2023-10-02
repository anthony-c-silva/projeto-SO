#include "processos.h"
#include <stdio.h>

#define MAX_PROCESSOS 100
#define QUANTUM 4 // Valor do quantum (ajuste conforme necessário)

typedef struct {
    int pid;
    int estado; // 0 para pronto, 1 para bloqueado, 2 para executando
    // Outros campos para informações do processo, se necessário
} Processo;

Processo tabela_processos[MAX_PROCESSOS];
int processo_em_execucao = -1;
int quantum_restante = 0;

// Implementação de uma fila simples de processos prontos
int fila_prontos[MAX_PROCESSOS];
int inicio_fila = 0;
int fim_fila = 0;

// Função para adicionar um processo à fila de prontos
void adicionar_a_fila(int pid) {
    fila_prontos[fim_fila] = pid;
    fim_fila = (fim_fila + 1) % MAX_PROCESSOS;
}

// Função para escolher o próximo processo a ser executado
int escolher_proximo() {
    if (inicio_fila != fim_fila) {
        int pid = fila_prontos[inicio_fila];
        inicio_fila = (inicio_fila + 1) % MAX_PROCESSOS;
        return pid;
    }
    return -1; // Retorna -1 se a fila estiver vazia
}

void init_processos() {
    // Inicializar a tabela de processos e outras variáveis globais
    // ...
}

void salvar_estado(Processo *processo) {
    // Implementar a lógica para salvar o estado do processador
    printf("Salvando estado do processador para o processo com PID %d\n", processo->pid);
}

void recuperar_estado(Processo *processo) {
    // Implementar a lógica para recuperar o estado do processador
    printf("Recuperando estado do processador para o processo com PID %d\n", processo->pid);
}

void escalonador() {
    if (quantum_restante == 0) {
        if (processo_em_execucao != -1) {
            salvar_estado(&tabela_processos[processo_em_execucao]);
            adicionar_a_fila(processo_em_execucao);
        }
        processo_em_execucao = escolher_proximo();
        quantum_restante = QUANTUM;
        if (processo_em_execucao != -1) {
            recuperar_estado(&tabela_processos[processo_em_execucao]);
        }
    }
    quantum_restante--;
}

void tratador_interrupcao() {
    if (processo_em_execucao != -1) {
        salvar_estado(&tabela_processos[processo_em_execucao]);
        // Executar o tratador correspondente à interrupção
        // Executar uma função para tratar pendências
        escalonador();
        recuperar_estado(&tabela_processos[processo_em_execucao]);
    }
}

int criar_processo() {
    for (int i = 0; i < MAX_PROCESSOS; i++) {
        if (tabela_processos[i].pid == -1) {
            tabela_processos[i].pid = i; // Atribuir um PID único
            tabela_processos[i].estado = 1; // Definir o estado como pronto
            // Inicializar outras informações do processo, se necessário
            return i;
        }
    }
    return -1; // Retornar -1 se não houver espaço para mais processos
}

void encerrar_processo(int pid) {
    for (int i = 0; i < MAX_PROCESSOS; i++) {
        if (tabela_processos[i].pid == pid) {
            tabela_processos[i].pid = -1;
            tabela_processos[i].estado = 0;
            // Limpar outras informações do processo, se necessário
            break;
        }
    }
}

void realizar_entrada_saida(int pid) {
    // Implementar a lógica para realizar E/S em um terminal diferente com base no PID
    printf("Realizando E/S para o processo com PID %d\n", pid);
}
