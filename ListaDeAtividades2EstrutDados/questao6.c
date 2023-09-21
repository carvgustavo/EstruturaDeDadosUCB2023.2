/*Questão 6 - Escreva uma função em C que realize uma busca sequencial em uma matriz bidimensional de inteiros para
encontrar um valor específico fornecido pelo usuário. A função deve retornar a posição da primeira ocorrência do valor
ou informar que o valor não foi encontrado.*/

#include <stdio.h>
#include <stdlib.h>

void ProcurarValor(int arr[][2], int n, int valor) {
    int i, j, numEncontrado = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            if (arr[i][j] == valor) {
                printf("Valor encontrado na posicao (%d, %d)\n", i, j);
                numEncontrado = 1;
                break;
            }
        }
        if (numEncontrado) {
            break;
        }
    }
    if (!numEncontrado) {
        printf("Valor nao encontrado na matriz.\n");
    }
}

int main() {
    int arr[][2] = {{64, 10}, {34, 20}, {25, 30}, {12, 40}, {22, 50}, {11, 60}, {90, 70}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Matriz:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", arr[i][0], arr[i][1]);
    }

    int valor;
    printf("\nDigite o valor a ser procurado na matriz: ");
    scanf("%d", &valor);

    ProcurarValor(arr, n, valor);

    return 0;
}
