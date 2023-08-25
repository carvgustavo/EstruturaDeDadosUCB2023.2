/*Questão 5 - Crie uma struct chamada "Livro" com campos para título, autor e ano de publicação. Escreva um programa
que permita ao usuário adicionar informações de livros, listar todos os livros cadastrados e buscar livros por autor.*/

#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100

struct Livro {
    char titulo[50];
    char autor[50];
    int ano;
};

int main() {
    struct Livro livros[MAX_LIVROS];
    int numLivros = 0;

    while (1) {
        printf("1 - Adicionar livro\n");
        printf("2 - Listar os livros\n");
        printf("3 - Buscar livros pelo autor\n");
        printf("4 - Sair\n");

        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (numLivros >= MAX_LIVROS) {
                printf("O limite de livros foi atingido!\n");
            } else {
                struct Livro livro;
                printf("Informe o titulo do livro: ");
                scanf("%s", livro.titulo);
                printf("Informe o autor do livro: ");
                scanf("%s", livro.autor);
                printf("Informe o ano de publicacao do livro: ");
                scanf("%d", &livro.ano);
                livros[numLivros] = livro;
                numLivros++;
            }
        } else if (opcao == 2) {
            printf("Lista de livros:\n");
            for (int i = 0; i < numLivros; i++) {
                printf("%s, %s, %d\n", livros[i].titulo, livros[i].autor, livros[i].ano);
            }
        } else if (opcao == 3) {
            char autor[50];
            printf("Digite o nome do autor: ");
            scanf("%s", autor);
            printf("Livros do autor %s:\n", autor);
            for (int i = 0; i < numLivros; i++) {
                if (strcmp(livros[i].autor, autor) == 0) {
                    printf("%s, %s, %d\n", livros[i].titulo, livros[i].autor, livros[i].ano);
                }
            }
        } else if (opcao == 4) {
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
