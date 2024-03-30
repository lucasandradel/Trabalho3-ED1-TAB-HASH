#include "tab_hash.h"

void inicalizaTabHash(tipo_tab_hash *tbh) {
    int i;
    for (i = 0; i < TAM_HASH; i++) { // Percorre todas as posições do vetor tabela_hash.
        tbh->tabela_hash[i] = NULL; // Define todas as posições como NULL, indicando que estão vazias.
    }
}

 
tipo_no_hash *alocaNoHash(int id, char artista, char genero, char titulo,   double danceabilty) {
    tipo_no_hash *novo_no;
    novo_no = (tipo_no_hash*)malloc(sizeof(tipo_no_hash)); // Aloca memória para um novo nó.
    novo_no->id =id; // Atribui a chave ao novo nó.
    novo_no->artista = artista; // Atribui o dado ao novo nó.
    novo_no -> titulo = titulo;
    novo_no -> genre = genero;
    novo_no -> danceabily = danceabilty;
    novo_no->prox = NULL; // Define o próximo nó como NULL, já que é o último nó da lista.
    return novo_no; // Retorna o ponteiro para o novo nó alocado.
}

int funcaoHash(int id){
    return id%TAM_HASH;//pego a chave divido pelo tamanho e retorno o resto da divisão
}

tipo_no_hash *buscaTabHash(tipo_tab_hash *tbh, int id) {
    tipo_no_hash *aux;
    int pos;

    pos = funcaoHash(id); // Calcula a posição na tabela de hash usando a função de hash.

    if (tbh->tabela_hash[pos] == NULL) {
        return NULL; // Se não houver nenhum nó na posição calculada, retorna NULL, indicando que o nó com a chave não foi encontrado.
    } else {
        aux = tbh->tabela_hash[pos]; // Inicializa um ponteiro auxiliar para percorrer a lista encadeada nessa posição da tabela.

        while (aux != NULL) { // Percorre a lista encadeada.
            if (aux->id == id) {
                return aux; // Se encontrar um nó com a chave correspondente, retorna um ponteiro para esse nó.
            } else {
                aux = aux->prox; // Se não encontrar, avança para o próximo nó na lista.
            }
        }
        return NULL; // Se a chave não for encontrada em nenhum nó na lista, retorna NULL.
    }
}


void insereTabHash(tipo_tab_hash *tbh, int id, char artista, char genero, char titulo, double danceabilty) {
    int pos;
    tipo_no_hash *novo_no;

    // Verifica se já existe um nó com a mesma chave na tabela
    if (buscaTabHash(tbh,id ) == NULL) {
        // Calcula a posição na tabela de hash usando a função de hash
        pos = funcaoHash(id);
        // Aloca memória para um novo nó com a chave e o valor especificados
        novo_no = alocaNoHash(id, artista, genero, titulo, danceabilty);

        // Se a posição na tabela de hash estiver vazia
        if (tbh->tabela_hash[pos] == NULL) {
            tbh->tabela_hash[pos] = novo_no; // O novo nó é atribuído diretamente à posição
        } else {
            // Caso contrário, o novo nó é encadeado na lista existente nessa posição
            novo_no->prox = tbh->tabela_hash[pos];
            tbh->tabela_hash[pos] = novo_no;
        }
    }
}

/*
char removeTabHash(tipo_tab_hash *tbh, int chave) {
    tipo_no_hash *aux, *ant;
    int pos;
    char dado;

    // Verifica se o nó com a chave especificada está presente na tabela de hash
    aux = buscaTabHash(tbh, chave);
    if (aux != NULL) {
        pos = funcaoHash(chave);
        
        // Verifica se o nó a ser removido é o primeiro nó na posição da tabela de hash
        if (tbh->tabela_hash[pos] == aux) {
            dado = aux->valor;
            free(aux);
            tbh->tabela_hash[pos] = NULL; // Remove o nó da tabela e libera a memória
        } else {
            // Caso contrário, percorre a lista encadeada até encontrar o nó a ser removido
            ant = tbh->tabela_hash[pos];
            while (ant->prox != aux) {
                ant = ant->prox;
            }
            ant->prox = aux->prox; // Atualiza os ponteiros para remover o nó
        }
        dado = aux->valor;
        free(aux);
        return dado; // Retorna o valor do nó removido
    }
    return '\0'; // Retorna '\0' se o nó com a chave especificada não for encontrado na tabela
}*/

void imprimeTabHash(tipo_tab_hash*tbh){
    int i;
    tipo_no_hash * aux;

    printf("Tabela HASH:\n");
    for (i=0; i< TAM_HASH; i++){
        printf ("[%d] -> ", i);
        if (tbh-> tabela_hash[i] == NULL){
            printf(" (NULL)\n");
        }else{
            aux = tbh -> tabela_hash[i];
            while (aux != NULL)
            {
                    
                printf("id: [ %d ] artista: [ %c ] titulo: [ %c ] Genero: [ %c ] Danceabily: [ %f ] -> ", aux -> id, aux-> artista, aux -> titulo, aux -> genre, aux -> danceabily);
                aux = aux-> prox;
            }
            printf(" (NULL)\n");
        }

    }
}