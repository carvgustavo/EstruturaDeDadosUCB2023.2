/*Questão 2 - Compare o desempenho do algoritmo de ordenação por bolha com algoritmo de ordenação o quicksort e o mergesort, 
usando arrays de tamanhos diferentes. Meça o tempo de execução e compare os resultados.*/

/*Para comparar o desempenho dos algoritmos de ordenação, podemos medir o tempo de execução para ordenar arrays de diferentes 
tamanhos. Para isso, podemos usar a função clock() da biblioteca time.h. O código abaixo mostra como medir o tempo de execução 
dos algoritmos de ordenação por bolha, quicksort e mergesort para arrays de tamanhos diferentes:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    srand(time(NULL));

    int sizes[] = {1000, 10000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int arr[n];

        printf("Array de tamanho %d:\n", n);

        /* Preenche o array com números aleatórios */
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % n;
        }

        /* Mede o tempo de execução do algoritmo de ordenação por bolha */
        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();
        double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tempo de execucao do bubblesort: %f segundos\n", time_taken);

        /* Mede o tempo de execução do algoritmo de ordenação quicksort */
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % n;
        }
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();
        time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tempo de execucao do quicksort: %f segundos\n", time_taken);

        /* Mede o tempo de execução do algoritmo de ordenação mergesort */
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % n;
        }
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tempo de execucao do mergesort: %f segundos\n", time_taken);

        printf("\n");
    }

    return 0;
}

/*O resultado da comparação pode variar dependendo do hardware e do ambiente de execução, mas em geral 
o algoritmo de ordenação por bolha é o mais lento, seguido pelo quicksort e pelo mergesort. O mergesort 
costuma ser mais rápido que o quicksort para arrays grandes, mas para arrays pequenos o quicksort pode ser mais eficiente.*/