//Aula 01
#define MAX 100

//Definição dos tipos de dados e prototipo criação e limpeza da lista
struct DadosPessoais{
    char nome[30];
    int idade;
    double altura;
    double peso;
};

typedef struct lista Lista;

Lista* cria_lista();
void limpa_lista(Lista* li);

//Gerenciamento da lista, informações.
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);

//Inserção da na lista
int insere_lista_final(Lista* li, struct DadosPessoais al);
int insere_lista_inicio(Lista* li, struct DadosPessoais al);
int insere_lista_meio(Lista* li, struct DadosPessoais al);

//Remoção e consulta
int remove_lista_final(Lista* li);
int remove_lista_inicio(Lista* li);
int remove_lista_meio(Lista* li, struct DadosPessoais al);

int consulta_lista_pos(Lista* li, int pos, struct DadosPessoais *al);
int consulta_lista_conteudo(Lista* li, int idade, struct DadosPessoais *al);