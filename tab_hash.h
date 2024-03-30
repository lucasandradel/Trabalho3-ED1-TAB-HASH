#ifndef __TAB_HASH_H__
#define __TAB_HASH_H__

#include <stdlib.h>
#include <stdio.h>

#define TAM_HASH 10

struct est_no_hash
{
    int id;//chave que indentifica o conjunto de dados
    char artista;//dado que sera armazenado
    char titulo;
    char genre;
    double danceabily;

    struct est_no_hash *prox;//ponteiro para estabelecer o encadeamento 
};
typedef struct est_no_hash tipo_no_hash;

struct est_tab_hash
{
    tipo_no_hash *tabela_hash[TAM_HASH];
};
typedef struct est_tab_hash tipo_tab_hash;


//prototipagem
void inicalizaTabHash(tipo_tab_hash*);
tipo_no_hash *alocaNoHash( int, char, char, char,double);
int funcaoHash(int);//entrega a chave 
void insereTabHash(tipo_tab_hash*,  int, char, char, char,double);
char removeTabHash(tipo_tab_hash*, int);
tipo_no_hash *buscaTabHash(tipo_tab_hash*, int);//entrega a chave e busca a chave na tabela, devolvendo o indice do no
void imprimeTabHash(tipo_tab_hash*);




#endif
