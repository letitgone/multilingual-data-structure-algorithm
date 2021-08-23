#include <stdio.h>
#include <string.h>

char file_suffix(char *filename);

int main(void)
{
    char filename[] = "adfadd,d.fom.cc";
    char r = file_suffix(filename);
    printf("result: %c", r);
}

char file_suffix(char *filename)
{
    int length = strlen(filename);
    printf("length %d", length);
    for (int i = length; i > 0; i--)
    {
        if (filename[i] == '.')
        {
            return filename[++i];
        }
    }
    return '\0';
}