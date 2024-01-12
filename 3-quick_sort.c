#include "sort.h"

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high, size_t size) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            print_array(arr, size);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    print_array(arr, size);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, size_t size) {
    if (low < high) {
        int pi = partition(arr, low, high, size);
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

void quick_sort(int arr[], size_t size) {
    quickSort(arr, 0, size - 1, size);
}
