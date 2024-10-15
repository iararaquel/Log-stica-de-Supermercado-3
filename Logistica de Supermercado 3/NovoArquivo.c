#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"

Usuario* criar_lista_usuarios() {
    return NULL;
}

int login(Usuario *usuarios) {
    char nome[limite_NOME_TAMANHO];
    char senha[limite_SENHA_TAMANHO];

    printf("Login\nNome de usu�rio: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    Usuario *atual = usuarios;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0 && strcmp(atual->senha, senha) == 0) {
            printf("Login realizado com sucesso!\n");
            return 1;
        }
        atual = atual->prox;
    }

    printf("O nome de usu�rio ou senha est�o inv�lidos. Por favor, tente novamente.\n");
    return 0;
}

void cadastrar_usuario(Usuario **usuarios) {
    Usuario novo = (Usuario)malloc(sizeof(Usuario));
    if (!novo) {
        printf("Erro ao alocar mem�ria para novo usu�rio.\n");
        return;
    }

    printf("Cadastro de novo usu�rio\nNome de usu�rio: ");
    scanf("%s", novo->nome);
    printf("Senha: ");
    scanf("%s", novo->senha);
    printf("E-mail: ");
    scanf("%s", novo->email);

    novo->prox = *usuarios;
    *usuarios = novo;

    printf("Cadastro realizado com sucesso!\n");
}

void excluir_usuario(Usuario **usuarios) {
    char nome[limite_NOME_TAMANHO];
    printf("Digite o nome do usu�rio que deseja excluir: ");
    scanf("%s", nome);

    Usuario *atual = *usuarios, *anterior = NULL;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Usu�rio n�o encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *usuarios = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Usu�rio exclu�do com sucesso!\n");
}

void salvar_usuarios(Usuario *usuarios) {
    FILE *file = fopen("usuarios.dat", "wb");
    if (!file) {
        printf("Erro ao abrir arquivo para salvar usu�rio.\n");
        return;
    }

    Usuario *atual = usuarios;
    while (atual != NULL) {
        fwrite(atual, sizeof(Usuario), 1, file);
        atual = atual->prox;
    }

    fclose(file);
}

void carregar_usuarios(Usuario **usuarios) {
    FILE *file = fopen("usuarios.dat", "rb");
    if (!file) return;

    Usuario temp;
    while (fread(&temp, sizeof(Usuario), 1, file)) {
        Usuario novo = (Usuario)malloc(sizeof(Usuario));
        if (!novo) break;

        *novo = temp;
        novo->prox = *usuarios;
        *usuarios = novo;
    }

    fclose(file);
}

void liberar_lista_usuarios(Usuario *usuarios) {
    Usuario *temp;
    while (usuarios != NULL) {
        temp = usuarios;
        usuarios = usuarios->prox;
        free(temp);
    }
}