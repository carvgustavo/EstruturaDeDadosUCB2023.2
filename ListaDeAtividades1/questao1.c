/*Questão 1 - Crie uma struct chamada "Pessoa" que contenha os seguintes campos: nome, idade e altura. Em seguida,
escreva um programa que declare uma variável do tipo Pessoa, preencha seus campos e imprima os valores.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    char nome[20];
    char idade[3];
    float altura;
};

void Pessoa (struct Pessoa *p){
    printf("Informe o nome: ");
    fgets(p->nome, 20, stdin);
    printf("Informe a idade: ");
    fgets(p->idade, 3, stdin);
    printf("Informe a altura: ");
    scanf("%f", &p->altura);
}


int main(){

    struct Pessoa pessoa;
    Pessoa (&pessoa);
    printf("\nCadastro: \n");
    printf("Nome: %s", pessoa.nome);
    printf("Idade: %s", pessoa.idade);
    printf("\nAltura: %.2f", pessoa.altura);

    return 0;
}
