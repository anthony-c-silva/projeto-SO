#include "processos.h"
#include <stdio.h>

#define MAX_PROCESSOS 100

Processo tabela_processos[MAX_PROCESSOS];

int processo_em_execucao = -1;

void init_processos() {
    for (int i = 0; i < MAX_PROCESSOS; i++) {
        tabela_processos[i].pid = -1;
        tabela_processos[i].estado = 0;
        // Inicialize outras informações do processo, se necessário
    }
}

void salvar_estado(Processo *processo) {
    // Implemente a lógica para salvar o estado do processador
    printf("Salvando estado do processador para o processo com PID %d\n", processo->pid);
}

void recuperar_estado(Processo *processo) {
    // Implemente a lógica para recuperar o estado do processador
    printf("Recuperando estado do processador para o processo com PID %d\n", processo->pid);
}

void escalonador() {
    // Implemente um escalonador simples, por exemplo, selecionando o próximo processo pronto
    for (int i = 0; i < MAX_PROCESSOS; i++) {
        if (tabela_processos[i].estado == 1) {
            processo_em_execucao = i;
            printf("Processo com PID %d está em execução\n", tabela_processos[i].pid);
            break;
        }
    }
}

void tratador_interrupcao() {
    if (processo_em_execucao != -1) {
        salvar_estado(&tabela_processos[processo_em_execucao]);
        // Execute o tratador correspondente à interrupção
        // Execute uma função para tratar pendências
        escalonador();
        recuperar_estado(&tabela_processos[processo_em_execucao]);
    }
}

int criar_processo() {
    for (int i = 0; i < MAX_PROCESSOS; i++) {
        if (tabela_processos[i].pid == -1) {
            tabela_processos[i].pid = i; // Atribuir um PID único
            tabela_processos[i].estado = 1; // Definir o estado como pronto
            // Inicialize outras informações do processo, se necessário
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
    // Implemente a lógica para realizar E/S em um terminal diferente com base no PID
    printf("Realizando E/S para o processo com PID %d\n", pid);
}
