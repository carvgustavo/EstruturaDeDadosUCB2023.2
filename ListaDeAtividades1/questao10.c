/*Questão 10 - Crie uma struct chamada "Moeda" que possa armazenar valores em dólares e euros. Escreva um programa
que permita ao usuário escolher uma moeda e converter um valor entre dólares e euros, usando a taxa de câmbio
atual.*/

#include <stdio.h>

struct Moeda {
    float dolar;
    float euro;
};

float conversaoDolarEuro(float valor, float taxaCambio){
    return valor * taxaCambio;
}

float conversaoEuroDolar(float valor, float taxaCambio){
    return valor / taxaCambio;
}

int main(){
    struct Moeda moeda;
    float taxaCambio;
    char opcao;

    printf("Digite D para converter de Euro para Dolar ou E para converter de Dolar para Euro: ");
    scanf("%s", &opcao);

    switch (opcao)
    {
    case 'D':
    case 'd':
        printf("Informe a taxa atual do cambio (dolar por euro): ");
        scanf("%f", &taxaCambio);
        fflush(stdin);
        printf("Digite o valor em euro: ");
        scanf("%f", &moeda.euro);
        fflush(stdin);
        moeda.dolar = conversaoEuroDolar(moeda.euro, taxaCambio);
        printf("%.2f euros equivalem a %.2f dolares.\n", moeda.euro, moeda.dolar);
        break;
    case 'E':
    case 'e':
        printf("Informe a taxa atual do cambio (dolar por euro): ");
        scanf("%f", &taxaCambio);
        fflush(stdin);
        printf("Digite o valor em dolar: ");
        scanf("%f", &moeda.dolar);
        fflush(stdin);
        moeda.euro = conversaoDolarEuro(moeda.dolar, taxaCambio);
        printf("%.2f dolares equivalem a %.2f euros.\n", moeda.dolar, moeda.euro);
        break;
    default:
        printf("Caractere invalido.");
        break;
    }

    return 0; 
}