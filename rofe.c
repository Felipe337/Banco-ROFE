#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rofe.h"
#define TAMAX 100


void iniciafila(Fila *fila) 
    { fila->frente = -1;
    fila->tras = -1; }
    
    
int filavazia(Fila *fila)
    { return (fila->frente == -1 && fila->tras == -1); }
    
    
int filacheia(Fila *fila) 
    { return ((fila->tras + 1) % TAMAX == fila->frente); }
    
    
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); }
    
    
void inserefila(Fila *fila, int valor) {
    if (filacheia(fila)) {
        printf("\n\n\t\t __________________________________________________________\n");
        printf("\t\t|                                                          |\n");
        printf("\t\t| A fila está cheia. Não é possível gerar mais senhas.     |\n");
        printf("\t\t|__________________________________________________________|\n");
    return; }
    if (filavazia(fila)) {
        fila->frente = fila->tras = 0; }
            else { fila->tras = (fila->tras + 1) % TAMAX; }
                fila->itens[fila->tras] = valor; }


int removefila(Fila *fila) {
    int valor;
        if (filavazia(fila)) {
        printf("\n\n\t\t ____________________\n");
        printf("\t\t|                    |\n");
        printf("\t\t| A fila está vazia. |\n");
        printf("\t\t|____________________|\n");
    return -1; }
    valor = fila->itens[fila->frente];
    
    if (fila->frente == fila->tras) {
    fila->frente = fila->tras = -1; }
    
    else {
    fila->frente = (fila->frente + 1) % TAMAX; }
        return valor; }

void gerarsenha(Fila *fila, int servico, int *atendimentos, int limite) {
    int escolha;
    static int ordem = 1;
    inserefila(fila, ordem);
        if (*atendimentos >= limite) {
            printf("\n\n\t\t _______________________________________________________________________\n");
            printf("\t\t|                                                                       |\n");
            printf("\t\t| Limite de atendimentos atingido. Deseja continuar? (1 - Sim, 0 - Não) |\n");
            printf("\t\t|_______________________________________________________________________|\n");
                scanf("%d", &escolha);
    
    if (escolha == 1) { return; }
        else {
            printf("\n\n\t\t _____________________\n");
            printf("\t\t|                     |\n");
            printf("\t\t| Programa encerrado. |\n");
            printf("\t\t|_____________________|\n");
                exit(0); } }
            
        system("clear");
        printf("\t\t\t\t ______________\n");
        printf("\t\t\t\t|              |\n");
        printf("\t\t\t\t| SENHA GERADA |\n");
        printf("\t\t\t\t|______________|\n\n");
        printf(" ----------------------------------------------------------------------------------------------\n");
        printf("¦ Emitida   | SENHA %d | para o serviço: ", ordem);

    switch (servico) {
    case 1:
        printf("Atendimento Cliente Pessoa Física.\n");
        printf(" ----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t ____________\n");
        printf("\t\t\t\t|            |\n");
        printf("\t\t\t\t| AGUARDE... |\n");
        printf("\t\t\t\t|____________|\n\n");
    break;
    
    case 2:
        printf("Atendimento Benefícios Sociais.\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t ____________\n");
        printf("\t\t\t\t|            |\n");
        printf("\t\t\t\t| AGUARDE... |\n");
        printf("\t\t\t\t|____________|\n\n");
    break;
    
    case 3:
        printf("Atendimento Clientes Empresas.\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t ____________\n");
        printf("\t\t\t\t|            |\n");
        printf("\t\t\t\t| AGUARDE... |\n");
        printf("\t\t\t\t|____________|\n\n");
    break;
    
    default:
        printf("Outros\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t ____________\n");
        printf("\t\t\t\t|            |\n");
        printf("\t\t\t\t| AGUARDE... |\n");
        printf("\t\t\t\t|____________|\n\n");
            break; }
            ordem++;
            (*atendimentos)++; }


void chamarsenha(Fila *fila, int servico) {
    if (filavazia(fila)) {
        printf("\n\n\t\t ___________________________________________________\n");
        printf("\t\t|                                                   |\n");
        printf("\t\t| Não há senhas na fila para o serviço selecionado. |\n");
        printf("\t\t|___________________________________________________|\n"); }
        
        else {
        int senha = removefila(fila);
        system("clear");
        printf("\n\t\t _________\n");
        printf("\t\t|         |\n");
        printf("\t\t| CHAMADA |\n");
        printf("\t\t|_________|\n\n");
        printf("----------------------------------------------------\n");
        printf(" Senha %02d - ", senha);

    switch (servico) {
    case 1:
        printf("Atendimento Cliente Pessoa Física.\n");
        printf("----------------------------------------------------\n\n");
        printf("\t\t ____________\n");
        printf("\t\t|            |\n");
        printf("\t\t| AGUARDE... |\n");
        printf("\t\t|____________|\n\n");
    break;
    
    case 2:
        printf("Atendimento Benefícios Sociais.\n");
        printf("----------------------------------------------------\n\n");
        printf("\t\t ____________\n");
        printf("\t\t|            |\n");
        printf("\t\t| AGUARDE... |\n");
        printf("\t\t|____________|\n\n");
    break;
    
    case 3:
        printf("Atendimento Clientes Empresas.\n");
        printf("----------------------------------------------------\n\n");
        printf("\t\t ____________\n");
        printf("\t\t|            |\n");
        printf("\t\t| AGUARDE... |\n");
        printf("\t\t|____________|\n\n");
    break;
    
    default:
        printf("Outros.\n");
        printf("----------------------------------------------------\n\n");
        printf("\t\t ____________\n");
        printf("\t\t|            |\n");
        printf("\t\t| AGUARDE... |\n");
        printf("\t\t|____________|\n\n");
    break; } } }


void encerrarexp(Fila *fila1, Fila *fila2, Fila *fila3) {
    printf("\n\n\t\t ______________________\n");
    printf("\t\t|                      |\n");
    printf("\t\t| Senhas não atendidas |\n");
    printf("\t\t|______________________|\n");

    while (!filavazia(fila1)) {
        printf("\n\n\t\t ________________________________________________\n");
        printf("\t\t|                                                |\n");
        printf("\t\t| Senha %02d - Atendimento Cliente Pessoa Física   |\n", removefila(fila1));
        printf("\t\t|________________________________________________|\n"); }

    while (!filavazia(fila2)) {
        printf("\n\n\t\t _____________________________________________\n");
        printf("\t\t|                                             |\n");
        printf("\t\t| Senha %02d - Atendimento Benefícios Sociais   |\n", removefila(fila2));
        printf("\t\t|_____________________________________________|\n"); }

    while (!filavazia(fila3)) {
        printf("\n\n\t\t ____________________________________________\n");
        printf("\t\t|                                            |\n");
        printf("\t\t| Senha %02d - Atendimento Clientes Empresas   |\n", removefila(fila3));
        printf("\t\t|____________________________________________|\n"); }
    
        printf("\n\n\t\t ____________________________________________\n");
        printf("\t\t|                                            |\n");
        printf("\t\t| Expediente encerrado. Finalizando Programa |\n");
        printf("\t\t|____________________________________________|\n\n"); 
            sleep(5);
        exit(0); }


int definirlimiteatendimentos() {
    int limite;

        printf("\n\n\t\t\t\t***********************************************************************\n");
        printf("\t\t\t\t***********************************************************************\n");
        printf("\t\t\t\t**********                                                   **********\n");
        printf("\t\t\t\t**********          PROJETO DE ESTRUTURA DE DADOS I          **********\n");
        printf("\t\t\t\t**********                                                   **********\n");
        printf("\t\t\t\t***********************************************************************\n");
        printf("\t\t\t\t***********************************************************************\n\n");
            sleep(3);
            
    system("clear");
        printf("\n\n\t\t\t\t***************************************************************************\n");
        printf("\t\t\t\t***************************************************************************\n");
        printf("\t\t\t\t***************************************************************************\n");
        printf("\t\t\t\t**********                                                      **********\n");
        printf("\t\t\t\t**********               PROFESSOR DA DISCIPLINA                **********\n");
        printf("\t\t\t\t**********           _______________________________            **********\n");
        printf("\t\t\t\t**********          |                               |           **********\n");
        printf("\t\t\t\t**********          | CONSTANTINO DIAS DA CRUZ NETO |           **********\n");
        printf("\t\t\t\t**********          |_______________________________|           **********\n");
        printf("\t\t\t\t**********                                                      **********\n");
        printf("\t\t\t\t**********                                                      **********\n");
        printf("\t\t\t\t***************************************************************************\n");
        printf("\t\t\t\t***************************************************************************\n");
        printf("\t\t\t\t***************************************************************************\n\n");
            sleep(3);
    system("clear");

        printf("\n\n\t\t\t\t*********************************************************************************\n");
        printf("\t\t\t\t*********************************************************************************\n");
        printf("\t\t\t\t*********************************************************************************\n");
        printf("\t\t\t\t**********                                                             **********\n");
        printf("\t\t\t\t**********                      DESENVOLVEDORES                        **********\n");
        printf("\t\t\t\t**********             ___________________________________             **********\n");
        printf("\t\t\t\t**********            |                                   |            **********\n");
        printf("\t\t\t\t**********            |       FELIPE ALVES ARAUJO         |            **********\n");
        printf("\t\t\t\t**********            |               &                   |            **********\n");
        printf("\t\t\t\t**********            | ROBERTA RIBEIRO FERNANDEZ ASENCIO |            **********\n");
        printf("\t\t\t\t**********            |___________________________________|            **********\n");
        printf("\t\t\t\t**********                                                             **********\n");
        printf("\t\t\t\t**********                                                             **********\n");
        printf("\t\t\t\t*********************************************************************************\n");
        printf("\t\t\t\t*********************************************************************************\n");
        printf("\t\t\t\t*********************************************************************************\n");
            sleep(3);

    system("clear");
        printf("\n\n\t\t\t\t*****************************************************\n");
        printf("\t\t\t\t*****************************************************\n");
        printf("\t\t\t\t**********                                 **********\n");
        printf("\t\t\t\t**********       BEM VINDO AO ROFEBANK     **********\n");
        printf("\t\t\t\t**********                                 **********\n");
        printf("\t\t\t\t*****************************************************\n");
        printf("\t\t\t\t*****************************************************\n\n");
            sleep(2);
    
        printf("\t\t\t\t ____________\n");
        printf("\t\t\t\t|            |\n");
        printf("\t\t\t\t| AGUARDE... |\n");
        printf("\t\t\t\t|____________|\n");
            sleep(2);
    
        printf("\t\t\t\t _______________________________\n");
        printf("\t\t\t\t|                               |\n");
        printf("\t\t\t\t| Tecle Enter para continuar... |\n");
        printf("\t\t\t\t|_______________________________|\n");
            getchar();
            system("clear");
    
            printf("\n\n\t\t**********************************************************************\n");
            printf("\t\t**********************************************************************\n");
            printf("\t\t**********                                                  **********\n");
            printf("\t\t**********      ESCOLHA O LIMITE DE ATENDIMENTOS DO DIA     **********\n");
            printf("\t\t**********                                                  **********\n");
            printf("\t\t**********************************************************************\n");
            printf("\t\t**********************************************************************\n\n\n");

                while(1){
                    printf("\t\tDigite quantos clientes serão atendidos neste dia: ");
                    
                    if (scanf("%d", &limite) == 1) {
                        break; }
                        
                    else{ limparBufferEntrada();
                        printf("\n\n\t\t __________________\n");
                        printf("\t\t|                  |\n");
                        printf("\t\t| ENTRADA INVALIDA |\n");
                        printf("\t\t|__________________|\n\n");
                        printf(" Por favor, digite um numero.\n"); } }
                            system("clear");
                            return limite; }



void removerSenhaEspecifica(Fila *fila, int senha) {
    int posicao = -1;
    
        if (filavazia(fila)) {
            printf("\n\n\t\t ________________________________________________\n");
            printf("\t\t|                                                |\n");
            printf("\t\t| A fila está vazia. Não há senhas para remover. |\n");
            printf("\t\t|________________________________________________|\n");
                return; }

        for (int i = fila->frente; i != (fila->tras + 1) % TAMAX; i = (i + 1) % TAMAX) {
            if (fila->itens[i] == senha) {
                posicao = i;
                    break; } }

        if (posicao == -1) {
            printf("\n\n\t\t __________________________________________\n");
            printf("\t\t|                                          |\n");
            printf("\t\t| A senha %02d não foi encontrada na fila. |\n", senha);
            printf("\t\t|__________________________________________|\n");
                return; }

        for (int i = posicao; i != fila->tras; i = (i + 1) % TAMAX) {
            fila->itens[i] = fila->itens[(i + 1) % TAMAX]; }
        
        if (fila->frente == fila->tras) {
            fila->frente = fila->tras = -1; }
            
            else {
                fila->tras = (fila->tras - 1 + TAMAX) % TAMAX; }
                printf("\n\n\t\t __________________________________________\n");
                printf("\t\t|                                          |\n");
                printf("\t\t| Senha %02d removida da fila com sucesso. |\n", senha); 
                printf("\t\t|__________________________________________|\n\n"); 
                
}
