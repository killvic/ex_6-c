#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "person.h"

void printPerson(Person bufferPerson) {
    printf("%s,%s,%d,%d,%d,%d,%.2lf\n", (bufferPerson.firstName), (bufferPerson.lastName), (bufferPerson.dateOfBirth.day), (bufferPerson.dateOfBirth.month), (bufferPerson.dateOfBirth.year), (bufferPerson.height), (bufferPerson.weight));
}

void fprintPerson(Person bufferPerson, FILE* output) {
    fprintf(output, "%s,%s,%d,%d,%d,%d,%.2lf\n", (bufferPerson.firstName), (bufferPerson.lastName), (bufferPerson.dateOfBirth.day), (bufferPerson.dateOfBirth.month), (bufferPerson.dateOfBirth.year), (bufferPerson.height), (bufferPerson.weight));
}

void fprintfPersons(FILE* file, Person persons[], int numOfPersons) {   
    for (int i = 0; i < numOfPersons; i++) {
        fprintPerson(persons[i], file);
    }
}

void readToArray(Person persons[], int i, char buffer[]) { // transforms a string to a Person struct
    sscanf(buffer, "%[^,],%[^,],%d,%d,%d,%d,%lf", persons[i].firstName, persons[i].lastName, &(persons[i].dateOfBirth.day), &(persons[i].dateOfBirth.month), &(persons[i].dateOfBirth.year), &(persons[i].height), &(persons[i].weight));
}

void swapPersons(Person persons[], int i, int j) {
    Person bufferPerson = persons[i];
    persons[i] = persons[j];
    persons[j] = bufferPerson;
}

void load(const char* inputFile, Person persons[], int* numOfPersonsPtr) { // loads a file
    FILE* input = fopen(inputFile, "r");
    char buffer[MAX_STR_LEN] = {0};
    int i = 0;
    if (!input) {
        printf("File not found: %s\n", inputFile);
        return;
    }
    else {
        while (fgets(buffer, MAX_STR_LEN, input) != 0) {
            readToArray(persons, i++, buffer);
            memset(buffer, 0, MAX_STR_LEN);
        }
    }
    *numOfPersonsPtr = i;
}

int comparePersonByFirstName(Person persons[], int i, int j) {  // -1 - less, 1 - more, 0 - equal
    return strcmp(persons[i].firstName, persons[j].firstName);
}
int comparePersonByLastName(Person persons[], int i, int j) {
    return strcmp(persons[i].lastName, persons[j].lastName);
}
int comparePersonByWeight(Person persons[], int i, int j) { 
    if (persons[i].weight < persons[j].weight)
        return -1;
    else if (persons[i].weight == persons[j].weight)
        return 0;
    else return 1;
}
int comparePersonByHeight(Person persons[], int i, int j) {
    if (persons[i].height < persons[j].height)
        return -1;
    else if (persons[i].height == persons[j].height)
        return 0;
    else return 1;
}
int comparePersonByBMI(Person persons[], int i, int j) {
    double bmiI, bmiJ;
    bmiI = (persons[i].weight / ((persons[i].height / 100) * (persons[i].height / 100)));
    bmiJ = (persons[j].weight / ((persons[j].height / 100) * (persons[j].height / 100)));
    if (bmiI < bmiJ)
        return -1;
    else if (bmiI == persons[j].height)
        return 0;
    else return 1;
}
int comparePersonByDate(Person persons[], int i, int j) {
    if (persons[i].dateOfBirth.year > persons[j].dateOfBirth.year)
        return 1;
    else if (persons[i].dateOfBirth.year < persons[j].dateOfBirth.year)
        return -1;
    else {
        if (persons[i].dateOfBirth.month > persons[j].dateOfBirth.month)
            return 1;
        else if (persons[i].dateOfBirth.month < persons[j].dateOfBirth.month)
            return -1;
        else {
            if (persons[i].dateOfBirth.day > persons[j].dateOfBirth.day)
                return 1;
            else if (persons[i].dateOfBirth.day < persons[j].dateOfBirth.day)
                return -1;
            else return 0;
        }
    }
}