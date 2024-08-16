#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TAMAX 100

typedef struct {
    int itens[TAMAX];
    int frente;
    int tras;
} Fila;

void iniciafila(Fila *fila);
int filavazia(Fila *fila);
int filacheia(Fila *fila);
void limparBufferEntrada();
void inserefila(Fila *fila, int valor);
int removefila(Fila *fila);
void gerarsenha(Fila *fila, int servico, int *atendimentos, int limite);
void chamarsenha(Fila *fila, int servico);
void encerrarexp(Fila *fila1, Fila *fila2, Fila *fila3);
int definirlimiteatendimentos();
void removerSenhaEspecifica(Fila *fila, int senha);

