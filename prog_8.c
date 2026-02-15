#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;
int swaps = 0;

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swaps++;
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                swaps++;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        comparisons++;
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
    
    free(L);
    free(R);
}

void mergeSortHelper(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, i;
    
    printf("Enter the value of N: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    int *original = (int*)malloc(n * sizeof(int));
    
    srand(time(NULL));
    
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
        original[i] = arr[i];
    }
    
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    printf("\nNumbers before sorting:\n");
    printArray(original, n);
    
    comparisons = 0;
    swaps = 0;
    
    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            printf("\nUsing Bubble Sort\n");
            break;
        case 2:
            selectionSort(arr, n);
            printf("\nUsing Selection Sort\n");
            break;
        case 3:
            insertionSort(arr, n);
            printf("\nUsing Insertion Sort\n");
            break;
        case 4:
            mergeSort(arr, n);
            printf("\nUsing Merge Sort\n");
            break;
        default:
            printf("Invalid choice!\n");
            free(arr);
            free(original);
            return 1;
    }
    
    printf("\nNumbers after sorting:\n");
    printArray(arr, n);
    
    printf("\nTotal comparisons: %d\n", comparisons);
    if (choice != 4) {
        printf("Total swaps: %d\n", swaps);
    } else {
        printf("Total swaps: Not applicable for Merge Sort\n");
    }
    
    free(arr);
    free(original);
    
    return 0;
}