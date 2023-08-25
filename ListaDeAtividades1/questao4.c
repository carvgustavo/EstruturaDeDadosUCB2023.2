/*Questão 4 - Crie uma struct chamada "Contato" que armazene o nome e o número de telefone de uma pessoa. escreva
um programa que permita ao usuário adicionar contatos, listar todos os contatos e buscar um contato pelo nome.*/

#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[20];
};

void adicionarContato(struct Contato agenda[], int *numContatos) {
    printf("Digite o nome do contato: ");
    scanf("%s", agenda[*numContatos].nome);
    printf("Digite o telefone do contato: ");
    scanf("%s", agenda[*numContatos].telefone);
    (*numContatos)++;
}

void listarContatos(struct Contato agenda[], int numContatos) {
    printf("Lista de contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("%s - %s\n", agenda[i].nome, agenda[i].telefone);
    }
}

void buscarContato(struct Contato agenda[], int numContatos) {
    char nomeBusca[50];
    printf("Digite o nome do contato que deseja buscar: ");
    scanf("%s", nomeBusca);
    
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(agenda[i].nome, nomeBusca) == 0) {
            printf("%s - %s\n", agenda[i].nome, agenda[i].telefone);
            return;
        }
    }
    
    printf("Nenhum contato encontrado com esse nome.\n");
}

int main() {
    struct Contato agenda[100];
    int numContatos = 0;
    
    while (1) {
        printf("\nO que deseja fazer?\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("4 - Sair\n");
        
        int opcao;
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                adicionarContato(agenda, &numContatos);
                break;
            case 2:
                listarContatos(agenda, numContatos);
                break;
            case 3:
                buscarContato(agenda, numContatos);
                break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
    }
}
