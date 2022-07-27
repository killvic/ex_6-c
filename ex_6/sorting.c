#include "sorting.h"

void quicksort(Person arr[], int start, int stop, void (*swap)(Person*, int, int), int (*compare)(Person[], int, int)) {
    if (start >= stop - 1) {
        return;
    }
    int pivot = start;
    int j = start;
    for (int i = start + 1; i < stop; i++) {
        if (compare(arr, i, pivot) < 0) {
            j++;
            if (i != j) {
                swap(arr, i, j);
            }
        }
    }
    swap(arr, start, j);
    quicksort(arr, start, j, swap, compare);
    quicksort(arr, j + 1, stop, swap, compare);
}
