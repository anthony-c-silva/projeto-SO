#include "processos.h"

#define MAX_PROCESSOS 100 // Defina o número máximo de processos suportados

Processo tabela_processos[MAX_PROCESSOS];
int processo_em_execucao = -1; // Inicialmente nenhum processo em execução

void init_processos() {
    // Inicialize a tabela de processos e outras variáveis globais
    // ...
}

void salvar_estado(Processo *processo) {
    // Salve o estado do processador na entrada correspondente à estrutura do processo
    // ...
}

void recuperar_estado(Processo *processo) {
    // Recupere o estado do processador a partir da tabela para o processo em execução
    // ...
}

void escalonador() {
    // Implemente o escalonador simples aqui
    // ...
}

void tratador_interrupcao() {
    // Salve o estado do processador
    // Execute o tratador correspondente à interrupção
    // Execute uma função para tratar pendências
    // Execute o escalonador
    // Recupere o estado do processador
    // ...
}

int criar_processo() {
    // Implemente a chamada para criar um novo processo
    // ...
    return novo_pid; // Substitua 'novo_pid' pelo PID do novo processo
}

void encerrar_processo(int pid) {
    // Implemente a chamada para encerrar um processo
    // ...
}

void realizar_entrada_saida(int pid) {
    // Altere as chamadas de E/S para usar um terminal diferente dependendo do PID do processo
    // ...
}
