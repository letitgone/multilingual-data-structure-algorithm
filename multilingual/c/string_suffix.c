#include <stdio.h>
#include <string.h>

char *file_suffix(char *filename);

int main(void)
{
    char filename[] = "adfadd,d.fom.cdsafd.ddfdc";
    char *r = file_suffix(filename);
    printf("result: %s", r);
}

char *file_suffix(char *filename)
{
    int length = strlen(filename);
    printf("length %d", length);
    char *result = strrchr(filename, '.');
    int j, k;
    for (j = k = 0; result[j] != '\0'; j++)
    {
        if (result[j] != '.')
        {
            result[k++] = result[j];
        }
    }
    result[k] = '\0';
    printf("res: %s", result);
    return result;
}