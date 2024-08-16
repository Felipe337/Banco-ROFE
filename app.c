#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "app.h"
#define TAMAX 100



void menu() {
    int senhaRemover;
    int limiteatendimentos = definirlimiteatendimentos();
    int atendimentos = 0;
    Fila fila1, fila2, fila3;
    iniciafila(&fila1);
    iniciafila(&fila2);
    iniciafila(&fila3);
    int opcao, servico;

    do {
        printf("\n\n\t\t****************************************************************\n");
        printf("\t\t****************************************************************\n");
        printf("\t\t**********                MENU DE SERVIÇO             **********\n");
        printf("\t\t**********                                            **********\n");
        printf("\t\t**********     1) Emissão de senha de atendimento.    **********\n");
        printf("\t\t**********                                            **********\n");
        printf("\t\t**********     2) Chamada de senha para atendimento.  **********\n");
        printf("\t\t**********                                            **********\n");
        printf("\t\t**********     3) Remover senha da fila.              **********\n");
        printf("\t\t**********                                            **********\n");
        printf("\t\t**********     4) Encerrar expediente.                **********\n");
        printf("\t\t**********                                            **********\n");
        printf("\t\t****************************************************************\n");
        printf("\t\t****************************************************************\n\n\n");

        while(1){
            printf("\t\tEscolha o tipo de serviço:  ");

        if (scanf("%d", &opcao) == 1) {
            break;
        } else{
            limparBufferEntrada();
            printf("\n __________________\n");
            printf("|                  |\n");
            printf("| ENTRADA INVALIDA |\n");
            printf("|__________________|\n\n");
            
            printf("\t\t Por favor, digite um numero.\n"); } }

        switch (opcao) {
            case 1:
                system("clear");
                printf("\n\n\t\t****************************************************************\n");
                printf("\t\t****************************************************************\n");
                printf("\t\t**********      ESCOLHA O TIPO DE ATENDIMENTO         **********\n");
                printf("\t\t**********                                            **********\n");
                printf("\t\t**********     1) Atendimento Cliente Pessoa Física   **********\n");
                printf("\t\t**********                                            **********\n");
                printf("\t\t**********     2) Atendimento Benefícios Sociais      **********\n");
                printf("\t\t**********                                            **********\n");
                printf("\t\t**********     3) Atendimento Clientes Empresas       **********\n");
                printf("\t\t**********                                            **********\n");
                printf("\t\t**********     ∞) Outros.                             **********\n");
                printf("\t\t**********                                            **********\n");
                printf("\t\t****************************************************************\n");
                printf("\t\t****************************************************************\n");
            scanf("%d", &servico);
            gerarsenha((servico == 1) ? &fila1 : (servico == 2) ? &fila2 : &fila3, servico, &atendimentos, limiteatendimentos);
            sleep(10);
            system("clear");
            break;

            case 2:
                    system("clear");
                printf("\n\n\t\t***********************************************************\n");
                printf("\t\t***********************************************************\n");
                printf("\t\t**********      ESCOLHA QUAL SENHA CHAMAR        **********\n");
                printf("\t\t**********                                       **********\n");
                printf("\t\t**********     1) Cliente Pessoa Física          **********\n");
                printf("\t\t**********                                       **********\n");
                printf("\t\t**********     2) Benefícios Sociais             **********\n");
                printf("\t\t**********                                       **********\n");
                printf("\t\t**********     3) Clientes Empresas              **********\n");
                printf("\t\t**********                                       **********\n");
                printf("\t\t**********     ∞) Outros.                        **********\n");
                printf("\t\t**********                                       **********\n");
                printf("\t\t***********************************************************\n");
                printf("\t\t***********************************************************\n");
                    scanf("%d", &servico);
                    chamarsenha((servico == 1) ? &fila1 : (servico == 2) ? &fila2 : &fila3, servico);
                    sleep(10);
                    system("clear");
                        break;

            case 4:
                encerrarexp(&fila1, &fila2, &fila3);
                    sleep(5);
                    getchar();
                    break;

            case 3:
                    system("clear");
                printf("\t\t\t\t*******************************************************\n");
                printf("\t\t\t\t*******************************************************\n");
                printf("\t\t\t\t**********                                   **********\n");
                printf("\t\t\t\t**********      REMOVER SENHA DA FILA        **********\n");
                printf("\t\t\t\t**********                                   **********\n");
                printf("\t\t\t\t*******************************************************\n");
                printf("\t\t\t\t*******************************************************\n");
                printf("\n\t\tDigite a senha que deseja remover: ");
                    scanf("%d", &senhaRemover);
                    removerSenhaEspecifica((servico == 1) ? &fila1 : (servico == 2) ? &fila2 : &fila3, senhaRemover);
                    sleep(2);
                    system("clear");
                        break;    
    
            default:
                printf("\n\t\t __________________________________\n");
                printf("\t\t|                                  |\n");
                printf("\t\t| Opção inválida. Tente novamente. |\n");
                printf("\t\t|__________________________________|\n");
            break; } }

        while (opcao != 4); }
