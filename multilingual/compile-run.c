#include <stdio.h>
#include <stdlib.h>

// #define FILENAME ".multilingual"
#define FILENAME "/test.txt"

int main(int argc, char *argv[])
{
    // printf("argc: %d\n", argc);
    // printf("argv: %s\n", argv[0]);
    // printf("argv: %s\n", argv[1]);
    // if (argc != 2)
    // {
    //     printf("Arguments error!");
    //     return 1;
    // }
    // argv[1]
    // "multilingual-data-structure-algorithm"
    FILE *file;
    if ((file = fopen(FILENAME, "r")) == NULL)
    {
        file = fopen(FILENAME, "w");
        // printf("Cant't open %s\n", FILENAME);
        // return EXIT_FAILURE;
    }
    // char ch;
    // while ((ch = getc(file)) != EOF)
    // {
    //     ch += ch;
    // }
    fclose(file);

    return 0;
}