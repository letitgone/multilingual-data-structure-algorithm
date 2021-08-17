#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Arguments error!");
        return 1;
    }
    // argv[1]
    printf("argc: %d\n", argc);
    printf("argv: %s\n", argv[0]);
    printf("argv: %s\n", argv[1]);
    return 0;
}