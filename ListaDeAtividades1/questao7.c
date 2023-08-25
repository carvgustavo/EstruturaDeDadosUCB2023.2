/*Questão 7 - Crie uma struct chamada "ContaBancaria" com campos para nome do titular, número da conta e saldo.
Implemente funções para depositar, sacar e verificar o saldo.*/

#include <stdio.h>
#include <stdlib.h>

struct ContaBancaria
{
    char nomeTitular[50];
    int numeroConta;
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor){
    conta->saldo += valor;
}

void sacar(struct ContaBancaria *conta, float valor){
    if (conta->saldo >= valor){
        conta->saldo -= valor;
    }else{
        printf("Saldo insuficiente.\n");
    }
}

void verificaSaldo(struct ContaBancaria *conta){
    printf("Saldo atual: R$%.2f\n", conta->saldo);
}

int main(){

    int opcao;
    float valor;
    struct ContaBancaria conta;
    printf("Insira o nome do titular da conta: ");
    scanf("%s", conta.nomeTitular);
    printf("Informe o numero da conta: ");
    scanf("%d", &conta.numeroConta);
    printf("Digite o saldo: ");
    scanf("%f", &conta.saldo);

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Verificar saldo\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
            case 3:
                verificaSaldo(&conta);
                break;
            case 4:
                exit(0);
            default:
                printf("Opcão invalida.\n");
        }
    }

    return 0;




}
