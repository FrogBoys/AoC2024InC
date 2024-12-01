//
// Created by mattias on 12/1/24.
//
//
// Created by mattias on 12/1/24.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dataArray[1000];
int dataArray2[1000];

int Sub(int x, int y) {
    return abs(x - y);
}

int Mult(int x, int y) {
    return abs(x * y);
}
int countElement(int inputArray[], int arraySize, int elementCount)
{
    int count = 0;

    for ( int i = 0; i < arraySize; i++ )
    {
        if ( inputArray[i] == elementCount ) ++count;
    }

    return count;
}

void Part1(int dataArray1[], int dataArray2[]) {
    int count = 0;

    for (int i = 0; i < 1000; ++i) {
        count += Sub(dataArray2[i], dataArray1[i]);
    }
    printf("\nPart1: %d", count);
}

void Part2(int dataArray1[], int dataArray2[]) {
    int count = 0;
    for (int i = 0; i < 1000; ++i) {
        int idCount = countElement(dataArray2, 1000, dataArray1[i]);
        count += Mult(dataArray1[i], idCount);
    }
    printf("\nPart2: %d", count);

}

int comp(const void* a, const void* b) {

    return (*(int*)a - *(int*)b);
}

void OrderLists() {
    int n = sizeof(dataArray) / sizeof(dataArray[0]);
    // Sort the array using qsort
    qsort(dataArray, n, sizeof(int), comp);
    qsort(dataArray2, n, sizeof(int), comp);
}

void CreatList(FILE *fp) {
    char ch;
    char* value;
    int count = 0;
    int index = 0;
    int arrayIndex = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (isdigit(ch)) {
            value[count] = ch;
            count++;
        }
        else {
            int integerValue = atoi(value);
            count = 0;
            if (index % 2 == 0)
            {
                dataArray[arrayIndex] = integerValue;
            }
            else {
                dataArray[arrayIndex] = integerValue;
                arrayIndex++;
            }
            index++;
            memset(value,0,strlen(value));
        }
    }
}

int main()
{
    char *filename = "/home/mattias/CLionProjects/AoC2024InC/Inputs/inputday1";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }
    char ch;
    char* value;
    int count = 0;
    int index = 0;
    int arrayIndex = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (isdigit(ch)) {
            value[count] = ch;
            count++;
        }
        else if (count == 5) {
            int integerValue = atoi(value);
            count = 0;
            if (index % 2 == 0)
            {
                dataArray[arrayIndex] = integerValue;
            }
            else if (index % 2 == 1){
                dataArray2[arrayIndex] = integerValue;
                arrayIndex++;
            }
            index++;
            memset(value,0,strlen(value));
        }
    }
    fclose(fp);
    CreatList(fp);
    OrderLists();
    Part1(dataArray, dataArray2);
    Part2(dataArray, dataArray2);
}
