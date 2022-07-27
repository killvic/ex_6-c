#define _CRT_SECURE_NO_WARNINGS

#include "sorting.h"

#define MAX_LINES 100
const char* INPUTFILE = "persons.txt";
const char* OUTPUTFILE = "sorted.txt";

int main() {
    Person persons[MAX_LINES];
    int numOfPersons = 0;
    load(INPUTFILE, persons, &numOfPersons);

    FILE* output = fopen(OUTPUTFILE, "w");
    if (!output) {
        printf("Error with file: %s\n", OUTPUTFILE);
        return;
    }

    fprintf(output, "Unsorted:\n");
    fprintfPersons(output, persons, numOfPersons);
    
    quicksort(persons, 0, numOfPersons, swapPersons, comparePersonByFirstName);
    fprintf(output, "Sorted by First Name:\n");
    fprintfPersons(output, persons, numOfPersons);
    
    quicksort(persons, 0, numOfPersons, swapPersons, comparePersonByLastName);
    fprintf(output, "Sorted by Last Name:\n");
    fprintfPersons(output, persons, numOfPersons);

    quicksort(persons, 0, numOfPersons, swapPersons, comparePersonByDate);
    fprintf(output, "Sorted by Date:\n");
    fprintfPersons(output, persons, numOfPersons);

    quicksort(persons, 0, numOfPersons, swapPersons, comparePersonByHeight);
    fprintf(output, "Sorted by Height:\n");
    fprintfPersons(output, persons, numOfPersons);

    quicksort(persons, 0, numOfPersons, swapPersons, comparePersonByWeight);
    fprintf(output, "Sorted by Weight:\n");
    fprintfPersons(output, persons, numOfPersons);

    quicksort(persons, 0, numOfPersons, swapPersons, comparePersonByBMI);
    fprintf(output, "Sorted by BMI:\n");
    fprintfPersons(output, persons, numOfPersons);

    return 0;
}