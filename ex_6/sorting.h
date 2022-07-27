#include "person.h"

void quicksort(Person arr[], int start, int stop, void (*swap)(Person[], int, int), int (*compare)(Person[], int, int));