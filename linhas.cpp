// Copyright [2018] <Ana Paula Martins Tarchetti>"  [legal/copyright]
#include "../include/linhas.h"
#include<stdlib.h>
#define nao 0
#define sim 1
int quantidade_linhas(FILE *arquivo){
int quantidade=0;
char caractere;
int only_spaces, fim_comentario, pulou_linha;
only_spaces=sim;
do
{
    if(feof(arquivo)!=0)
    {
    break;
    }
    fscanf(arquivo, "%c", &caractere);
    if(caractere == '/'){
        fscanf(arquivo, "%c", &caractere);
        if(caractere == '/' && only_spaces == sim){
            while(caractere != '\n' && feof(arquivo) == 0){
                fscanf(arquivo, "%c", &caractere);            
            }
        }
        if(caractere == '*'){
            if(only_spaces == sim){
                fim_comentario = nao;
                do{
                    fscanf(arquivo, "%c", &caractere);
                        if(caractere == '*'){
                            fscanf(arquivo, "%c", &caractere);
                            if(caractere == '/'){
                                fim_comentario=sim;
                            }
                        }
                }while(feof(arquivo)== 0 && fim_comentario == nao);
                fscanf(arquivo, "%c", &caractere);
            }
            if(only_spaces == nao){
                pulou_linha = nao;
                fim_comentario = nao;
                do{
                    fscanf(arquivo, "%c", &caractere);
                        if(caractere == '\n'){
                                pulou_linha = sim;
                        }
                        if(caractere == '*'){
                            fscanf(arquivo, "%c", &caractere);
                            if(caractere == '/'){
                                fim_comentario=sim;
                            }
                        }
                }while(feof(arquivo)== 0 && fim_comentario == nao);
                fscanf(arquivo, "%c", &caractere);
                if(pulou_linha == sim){
                    quantidade++;
                    only_spaces = sim;                
                }
            }
        }
    }
    if(caractere != ' ' && caractere != '\n' && caractere != '\t'){
        only_spaces = nao;
    }
    if(caractere == '\n')
    {
        if(only_spaces == nao){
             quantidade++;       
        }
        only_spaces = sim;
    }
}while(1);
return quantidade;
}
