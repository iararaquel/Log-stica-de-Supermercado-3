#ifndef ITENS_H
#define ITENS_H

#define limite_NOME_TAMANHO 50

typedef struct Item {
    char nome[limite_NOME_TAMANHO];
    float preco;
    int quantidade;
    struct Item *prox;
} Item;

Item* criar_lista_itens();
void cadastrar_item(Item **produtos);
void listar_itens(Item *produtos);
void editar_item(Item *produtos);
void excluir_item(Item **produtos);
void buscar_item(Item *produtos);
void salvar_itens(Item *produtos);
void carregar_itens(Item **produtos);
void ordenar_itens(Item **produtos);
void liberar_lista_itens(Item *produtos);

#endif