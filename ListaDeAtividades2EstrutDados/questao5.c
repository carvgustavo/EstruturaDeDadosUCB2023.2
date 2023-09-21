/*Questão 5 - Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo)
usando o algoritmo de ordenação por inserção.*/

#include <stdio.h>
#include <stdlib.h> 

void insertionSort(int arr[][2], int n) {
    int i, j, key1, key2;
    for (i = 1; i < n; i++) {
        key1 = arr[i][0];
        key2 = arr[i][1];
        j = i - 1;

        // Move os elementos maiores que a chave para a frente
        while (j >= 0 && arr[j][0] > key1) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
            j--;
        }

        // Insere a chave na posição correta
        arr[j + 1][0] = key1;
        arr[j + 1][1] = key2;
    }
}

int main() {
    int arr[][2] = {{64, 10}, {34, 20}, {25, 30}, {12, 40}, {22, 50}, {11, 60}, {90, 70}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Matriz original:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", arr[i][0], arr[i][1]);
    }

    insertionSort(arr, n);

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", arr[i][0], arr[i][1]);
    }

    return 0;
}
