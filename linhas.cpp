// Copyright [2018] <Ana Paula Martins Tarchetti>"  [legal/copyright]
#include "../include/linhas.h"
#include<stdlib.h>
#define nao 0
#define sim 1
int quantidade_linhas(FILE *arquivo){
int quantidade=0;
char caractere;
int only_spaces;
only_spaces=sim;
do
{
    fscanf(arquivo, "%c", &caractere);
    if(feof(arquivo))
    {
    break;
    }
    if(caractere == '\n')
    {
    quantidade++;
    }
}while(1);
return quantidade;
}
