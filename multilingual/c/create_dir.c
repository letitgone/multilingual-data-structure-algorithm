/**
 * @Author ZhangGJ
 * @Date 2021/09/04 10:39
 */
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

void create_target(char *project_url);

void str_copy(char *p1, char *p2);

int main(void)
{
    create_target("/Users/zhanggj/Desktop");
}

void create_target(char *project_url)
{
    char base1[300] = "";
    char base2[300] = "";
    char base3[300] = "";
    str_copy(base1, project_url);
    str_copy(base2, project_url);
    str_copy(base3, project_url);
    strcat(base1, "/java");
    strcat(base2, "/c");
    strcat(base3, "/cpp");
    int i = mkdir(base1, 0777);
    int j = mkdir(base2, 0777);
    int k = mkdir(base3, 0777);
    printf("");
}


void str_copy(char *p1, char *p2)
{
    while (*p2 != '\0')
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
}
