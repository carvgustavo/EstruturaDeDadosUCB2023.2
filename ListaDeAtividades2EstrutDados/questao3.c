/*Questão 3 - Implemente uma versão do algoritmo de ordenação por inserção que ordene em ordem decrescente em
vez de crescente.*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move os elementos maiores para a direita */
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);

    printf("\nArray ordenado em ordem decrescente: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
