#include <stdlib.h>
#include "Pessoa.h"


struct lista{
    int qtd;
    struct DadosPessoais dados[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
    }
    return li;
}

void limpa_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista* li){
    if(li == NULL){ return -1;}
    else{ return li->qtd;}
}

int lista_cheia(Lista* li){
    if(li == NULL){ return -1;}
    else{ return (li->qtd == MAX);}
}

int lista_vazia(Lista* li){
    if(li == NULL){return -1;}
    else{return (li->qtd == 0);}
}

int insere_lista_final(Lista* li, struct DadosPessoais al){
    if(li == NULL || lista_cheia(li)){
        return 0;
    }else{
        li->dados[li->qtd] = al;
        li->qtd++;
        return 1;
    }
}

int insere_lista_inicio(Lista* li, struct DadosPessoais al){
    if(li == NULL || lista_cheia(li)){
        return 0;
    }else{
        int i;
        for(i = li->qtd-1; i>=0; i--){
            li->dados[i+1] = li->dados[i];
        }
        li->dados[0] = al;
        li->qtd++;
        return 1;
    }
}

int insere_lista_meio(Lista* li, struct DadosPessoais al){
    if(li == NULL || lista_cheia(li)){
        return 0;
    }else{
        int i, k;
        while (i < li->qtd && li->dados->idade < al.idade){ i++; }
        for(k = li->qtd-1; k>=i; k--){
            li->dados[k+1] = li->dados[k];
        }
        li->dados[i] = al;
        li->qtd++;
        return 1;
    }
}

int remove_lista_final(Lista* li){
    if(li == NULL || li->qtd == 0){ return 0;}
    else{ 
        li->qtd--;
        return 1;
    }
}

int remove_lista_inicio(Lista* li){
    if(li == NULL || li->qtd == 0){ return 0;}
    else{
        int k;
        for(k = 0; k < li->qtd-1; k++){
            li->dados[k] = li->dados[k+1];
        }
        li->qtd--;
        return 1;
    }
}

int remove_lista_meio(Lista* li, struct DadosPessoais al){
    if(li == NULL || li->qtd == 0){ return 0;}
    else{
        int k, i;
        while (i < li->qtd && li->dados->nome != al.nome){i++;}
        if(i == li->qtd){return 0;}
        else{
            for(k = i; k<=li->qtd-1; k++){
                li->dados[k] = li->dados[k+1];
            }
            li->qtd--;
            return 1;
        }
    }
}

int consulta_lista_pos(Lista* li, int pos, struct DadosPessoais *al){
    if(li == NULL || pos <= 0 || pos > li->qtd){
        return 0;
    }else{
        *al = li->dados[pos -1];
        return 1;
    }
}

int consulta_lista_conteudo(Lista* li, int idade, struct DadosPessoais *al){
    if(li == NULL) {return 0;}
    else{
        int i;
        while(i < li->qtd && li->dados[i].idade != idade){ i++;}
        if(i == li->qtd){return 0;}
        else{
            *al = li->dados[i];
            return 1;
        }
    }
}