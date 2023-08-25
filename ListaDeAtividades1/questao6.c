/*Questão 6 - Crie uma struct chamada "Estudante" com campos para nome, matrícula e notas em três disciplinas.
Implemente funções para calcular a média das notas e determinar se um aluno está aprovado (média maior ou igual a
7).*/

#include <stdio.h>
#include <stdlib.h>

struct Estudante{
    char nome[30];
    char matricula[12];
    float nota1, nota2, nota3;
};

float calculoMedia(struct Estudante estudante){
    return (estudante.nota1 + estudante.nota2 + estudante.nota3) / 3;
}

void aprovado (struct Estudante estudante){
    float mediaNotas = calculoMedia(estudante);
    if(mediaNotas >= 7){
        printf("%s esta aprovado(a) com media %.2f.\n", estudante.nome, mediaNotas);
    }else{
        printf("%s nao esta aprovado(a), com media de %.2f.\n", estudante.nome, mediaNotas);
    }
}

int main(){
    struct Estudante estudante;
    printf("Insira o nome do estudante: ");
    fgets(estudante.nome, 30, stdin);
    printf("Insira a matricula do aluno: ");
    fgets(estudante.matricula, 12, stdin);
    printf("Informe a primeira nota: ");
    scanf("%f", &estudante.nota1);
    printf("Informe a segunda nota: ");
    scanf("%f", &estudante.nota2);
    printf("Informe a terceira nota: ");
    scanf("%f", &estudante.nota3);

    aprovado(estudante);

    return 0;
}
