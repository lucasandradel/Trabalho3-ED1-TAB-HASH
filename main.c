#include <stdio.h>
#include <stdlib.h>


#include "tab_hash.h"


int main(int argc, char *argv[]){
    tipo_tab_hash minha_tab_hash;

    inicalizaTabHash(&minha_tab_hash);
    tipo_no_hash *aux;

    insereTabHash(&minha_tab_hash, 1, 'A', 'T','G', 0.5 );
    insereTabHash(&minha_tab_hash, 2, 'A', 'T','G', 0.5 );
    insereTabHash(&minha_tab_hash, 3, 'A', 'T','G', 0.5 );
    insereTabHash(&minha_tab_hash, 4, 'A', 'T','G', 0.5 );
    insereTabHash(&minha_tab_hash, 5, 'A', 'T','G', 0.5 );

    imprimeTabHash(&minha_tab_hash);
    int id;
    id = 1;
    
    aux = buscaTabHash(&minha_tab_hash, id);
    if (aux != NULL){
        printf ("\n id [%d] encontrado: Artista = [%c] Titulo = [%c] Gênero = [%c] Danceabily = [%f] \n\n", id, aux -> artista, aux -> titulo, aux -> genre, aux-> danceabily);
    }else{
        printf("chave não encontrada\n");

    }

    //printf("Removido:  %c\n\n", removeTabHash(&minha_tab_hash, 1));
    //imprimeTabHash (&minha_tab_hash);

}