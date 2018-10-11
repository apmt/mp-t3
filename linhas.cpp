// Copyright [2018] <Ana Paula Martins Tarchetti>"  [legal/copyright]
#include "../include/linhas.hpp"
#include<stdlib.h>
#define nao 0
#define sim 1
/*************************************************************************
*Função: Contar quantidade de linhas válidas em um código em C++
*Descrição
*   Conta quantas linhas há em um código em C++, desconsiderando linhas 
*   em branco e linhas apenas com comentário, seja comentários
*   do tipo barra-barra ou do tipo barra-asterisco-asterisco-barra.
*Parâmetros
*   arquivo - Ponteiro para um arquivo '.cpp' de um código escrito em C++
*Valor retornado
*   quantidade - Número de linhas válidas de código no arquivo.
*Assertivas de entrada
*   arquivo != NULL
**************************************************************************/
int quantidade_linhas(FILE *arquivo) {
    int quantidade = 0;
    char caractere;
    int only_spaces, fim_comentario, pulou_linha;
    only_spaces = sim;
// Ler cada caractere do código
    while (!feof(arquivo)) {
        fscanf(arquivo, "%c", &caractere);
        if (caractere == '/') {
            fscanf(arquivo, "%c", &caractere);
            // Comentário do tipo '//'
            if (caractere == '/' && only_spaces == sim) {
                // Ler até o final do comentário
                while (caractere != '\n' && feof(arquivo) == 0) {
                    fscanf(arquivo, "%c", &caractere);
                }
            }
            // Comentário do tipo '/**/'
            if (caractere == '*') {
                if (only_spaces == sim) {
                    fim_comentario = nao;
                    // Ler até o final do comentário
                    do {
                        fscanf(arquivo, "%c", &caractere);
                            if (caractere == '*') {
                                fscanf(arquivo, "%c", &caractere);
                                if (caractere == '/') {
                                    fim_comentario = sim;
                                }
                            }
                    } while (feof(arquivo) == 0 && fim_comentario == nao);
                    fscanf(arquivo, "%c", &caractere);
                }
                if (only_spaces == nao) {
                    pulou_linha = nao;
                    fim_comentario = nao;
                    // Ler até o final do comentário
                    do {
                        fscanf(arquivo, "%c", &caractere);
                            if (caractere == '\n') {
                                    pulou_linha = sim;
                            }
                            if (caractere == '*') {
                                fscanf(arquivo, "%c", &caractere);
                                if (caractere == '/') {
                                    fim_comentario = sim;
                                }
                            }
                    }while(feof(arquivo) == 0 && fim_comentario == nao);
                    fscanf(arquivo, "%c", &caractere);
                    if (pulou_linha == sim) {
                        quantidade++;
                        only_spaces = sim;
                    }
                }
            }
        }
        if (caractere != ' ' && caractere != '\n' && caractere != '\t') {
            only_spaces = nao;
        }
        if (caractere == '\n') {
            if (only_spaces == nao) {
                 quantidade++;
            }
            only_spaces = sim;
        }
    }
    return quantidade;
}
