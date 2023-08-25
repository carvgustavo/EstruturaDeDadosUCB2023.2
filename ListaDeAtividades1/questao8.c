/*Questão 8 - Crie uma struct chamada "Produto" com campos para nome, preço e quantidade em estoque. Escreva um
programa que permita ao usuário comprar produtos, atualizando o estoque e calculando o total da compra.*/

#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    float preco;
    int qtd_estoque;
};

void comprar(struct Produto *produto, int qtd) {
    if (produto->qtd_estoque >= qtd) {
        produto->qtd_estoque -= qtd;
        printf("%d %s comprado(s) por R$%.2f cada.\n", qtd, produto->nome, produto->preco);
    } else {
        printf("Estoque insuficiente.\n");
    }
}

void atualizar_estoque(struct Produto *produto, int qtd) {
    produto->qtd_estoque += qtd;
}

float calcular_total(float *precos, int *qtds, int n) {
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        total += precos[i] * qtds[i];
    }
    return total;
}

int main() {
    struct Produto produtos[] = {
        {"Arroz", 10.0, 100},
        {"Feijao", 8.0, 50},
        {"Macarrao", 5.0, 200},
        {"Oleo", 7.0, 80},
        {"Sal", 2.0, 150}
    };
    int n_produtos = sizeof(produtos) / sizeof(produtos[0]);

    int opcao;
    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Fazer uma compra\n");
        printf("2 - Atualizar o estoque\n");
        printf("3 - Calcular o total da compra\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int codigo, qtd;
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade: ");
                scanf("%d", &qtd);

                if (codigo >= 1 && codigo <= n_produtos) {
                    comprar(&produtos[codigo - 1], qtd);
                } else {
                    printf("Codigo invalido.\n");
                }
                break;
            }
            case 2: {
                int codigo, qtd;
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade: ");
                scanf("%d", &qtd);

                if (codigo >= 1 && codigo <= n_produtos) {
                    atualizar_estoque(&produtos[codigo - 1], qtd);
                    printf("%d %s adicionado ao estoque.\n", qtd, produtos[codigo - 1].nome);
                } else {
                    printf("Codigo invalido.\n");
                }
                break;
            }
            case 3: {
                float precos[n_produtos];
                int qtds[n_produtos];
                int n_itens = 0;

                for (int i = 0; i < n_produtos; i++) {
                    if (produtos[i].qtd_estoque > 0) {
                        precos[n_itens] = produtos[i].preco;
                        printf("%d - %s (R$%.2f)\n", n_itens + 1, produtos[i].nome, produtos[i].preco);
                        printf("Quantidade em estoque: %d\n", produtos[i].qtd_estoque);
                        printf("Digite a quantidade desejada: ");
                        scanf("%d", &qtds[n_itens]);
                        n_itens++;
                    }
                }

                float total = calcular_total(precos, qtds, n_itens);
                printf("\nTotal da compra: R$%.2f\n", total);
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}
