/**
 * @Author ZhangGJ
 * @Date 2021/09/02 10:44
 */
#include <stdio.h>

int main()
{
    FILE *fp;
    char test[100];
    scanf("123 : %s\n", test);
    fp = fopen("/Users/zhanggj/Downloads/clion-projects/multilingual-data-structure-algorithm/multilingual/c/file.txt", "w+");
    fprintf(fp, "%s %s %s %s", "We", "are", "in", test);
    fclose(fp);
    return (0);
}