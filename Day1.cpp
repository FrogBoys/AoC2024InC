//
// Created by mattias on 12/1/24.
//

#include "Day1.h"
#include <stdio.h>

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
    while ((ch = fgetc(fp)) != EOF) {

        putchar(ch);
    }


    fclose(fp);

}


