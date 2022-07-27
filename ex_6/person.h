#include <stdio.h>

#pragma once

#define MAX_STR_LEN 100 
#define MAX_LINES 100
#define DELIM ","
#define DELIM_CHAR ','

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char firstName[MAX_STR_LEN];
    char lastName[MAX_STR_LEN];
    Date dateOfBirth;
    int height;
    double weight;
} Person;


void printPerson(Person bufferPerson);
void fprintPerson(Person bufferPerson, FILE* output);
void fprintfPersons(FILE* file, Person persons[], int numOfPersons);
void load(const char* inputFile, Person persons[], int* numOfPersonsPtr);
void swapPersons(Person persons[], int i, int j);

int comparePersonByFirstName(Person persons[], int i, int j);
int comparePersonByLastName(Person persons[], int i, int j);
int comparePersonByWeight(Person persons[], int i, int j);
int comparePersonByHeight(Person persons[], int i, int j);
int comparePersonByBMI(Person persons[], int i, int j);
int comparePersonByDate(Person persons[], int i, int j);