#ifndef USUARIOS_H
#define USUARIOS_H

#define limite_NOME_TAMANHO 50
#define limite_EMAIL_TAMANHO 80
#define limite_SENHA_TAMANHO 20

typedef struct Usuario {
    char nome[limite_NOME_TAMANHO];
    char senha[limite_SENHA_TAMANHO];
    char email[limite_EMAIL_TAMANHO];
    struct Usuario *prox;
} Usuario;

Usuario* criar_lista_usuarios();
int login(Usuario *usuarios);
void cadastrar_usuario(Usuario **usuarios);
void excluir_usuario(Usuario **usuarios);
void salvar_usuarios(Usuario *usuarios);
void carregar_usuarios(Usuario **usuarios);
void liberar_lista_usuarios(Usuario *usuarios);

#endif