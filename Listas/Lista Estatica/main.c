#include <stdio.h>
#include "Pessoa.h"
#include <string.h>

int main(){
    //Aula 01
    Lista *li;
    li = cria_lista();
    
    //Aula 02
    int tamanho = tamanho_lista(li);
    int cheia = lista_cheia(li);
    int vazia = lista_vazia(li);
    printf("Valor : %i\nCheia? : %i\nVazia? : %i", tamanho, cheia, vazia);

    //Aula 03
    struct DadosPessoais dados;
    strcpy(dados.nome, "Kinn"); dados.altura = 1.75; dados.idade = 11; dados.peso = 50.0;
    int adicionar_inicio = insere_lista_inicio(li, dados);
    
    strcpy(dados.nome, "Kinn"); dados.altura = 1.75; dados.idade = 13; dados.peso = 50.0;
    int adicionar_meio = insere_lista_meio(li, dados);

    strcpy(dados.nome, "Kinn"); dados.altura = 1.75; dados.idade = 14; dados.peso = 50.0;
    int adicionar_final = insere_lista_final(li, dados);

    printf("\n\nResultado insercao final? : %i", adicionar_final);
    printf("\nResultado insercao inicio? : %i", adicionar_inicio);
    printf("\nResultados insercao meio? : %i", adicionar_meio);
    
    //Aula 05
    int resposta_consulta_pos = consulta_lista_pos(li, 1, &dados);
    printf("\n\nNome : %s\nIdade : %i", dados.nome, dados.idade);

    int resposta_consulta_conteudo = consulta_lista_conteudo(li, 13, &dados);
    printf("\n\nNome : %s\nIdade : %i", dados.nome, dados.idade);

    //Aula 04
    int remover_inicio = remove_lista_inicio(li);
    int remover_meio = remove_lista_meio(li, dados);
    int remover_final = remove_lista_final(li);

    printf("\n\nResultado remocao final? : %i", remover_final);
    printf("\nResultado remocao inicio? : %i", remover_inicio);
    printf("\nResultados remocao meio? : %i", remover_meio);

    limpa_lista(li);
    return 0;
}