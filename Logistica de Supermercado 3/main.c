#include <stdio.h>
#include <locale.h>
#include "usuarios.h"
#include "itens.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    Usuario *usuarios = criar_lista_usuarios();
    Item *produtos = criar_lista_itens();

    carregar_usuarios(&usuarios);
    carregar_itens(&produtos);

    int opcao;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Login\n2. Cadastrar usuário\n3. Cadastrar item\n4. Listar itens\n5. Editar item\n6. Excluir item\n7. Buscar item\n8. Ordenar itens\n9. Excluir usuário\n10. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                login(usuarios);
                break;
            case 2:
                cadastrar_usuario(&usuarios);
                break;
            case 3:
                cadastrar_item(&produtos);
                break;
            case 4:
                listar_itens(produtos);
                break;
            case 5:
                editar_item(produtos);
                break;
            case 6:
                excluir_item(&produtos);
                break;
            case 7:
                buscar_item(produtos);
                break;
            case 8:
                ordenar_itens(&produtos);
                printf("Itens ordenados com sucesso!\n");
                break;
            case 9:
                excluir_usuario(&usuarios);
                break;
            case 10:
                salvar_usuarios(usuarios);
                salvar_itens(produtos);
                liberar_lista_usuarios(usuarios);
                liberar_lista_itens(produtos);
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}