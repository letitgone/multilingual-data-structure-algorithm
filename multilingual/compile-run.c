#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define URL_CONFIG "/tmp/multilingual.conf"

//#define PROJECT_NAME "multilingual-data-structure-algorithm"

#define MAX_LINE 1024

void search_file(char *target_file, char *file_dir, unsigned long file_dir_length);

void split(char *src, const char *separator, char **dest, int *num);

unsigned int str_length(const char *str);

void str_copy(char *p1, char *p2);

void create_target(char *project_url);

char COMMAND_CD[600] = "cd ";

char FULL_URL[300];

char CD_URL[300];

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Arguments error!");
        return EXIT_FAILURE;
    }
    char *filename = argv[1];
    FILE *file = NULL;
    char project_url[MAX_LINE];
    if ((access(URL_CONFIG, F_OK) == -1))
    {
        printf("Please enter project file url: \n");
		printf("like this:/home/projects/multilingual-data-structure-algorithm/\n or /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/\n");
        scanf("%s", project_url);
        file = fopen(URL_CONFIG, "a+");
        if (file == NULL)
        {
            printf("Create error!");
            return EXIT_FAILURE;
        }
        else
        {
            fprintf(file, "%s", project_url);
            if (fclose(file) != 0)
            {
                printf("Error in closing file.\n");
            }
        }
    }
    else
    {
        if ((file = fopen(URL_CONFIG, "r")) == NULL)
        {
            printf("File error!");
            return EXIT_FAILURE;
        }
        unsigned long len;
        while (fgets(project_url, MAX_LINE, file) != NULL)
        {
            len = strlen(project_url);
            project_url[len] = '\0';
        }
    }
    create_target(project_url);
    search_file(filename, project_url, str_length(project_url));
    if (FULL_URL[0] == '\0')
    {
        printf("File error!");
        return EXIT_FAILURE;
    }
    char *split_name[2] = {};
    int num = 2;
    split(filename, ".", split_name, &num);
    char *suffix = split_name[1];
    char *name = split_name[0];
    char *target_path = strcat(project_url, "target");
    if (strcmp(suffix, "c") == 0)
    {
        /**
         * cd /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/multilingual/c &&
         * gcc hello_c.c -std=c11 -o /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/target/c/hello_c &&
         * /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/target/c/hello_c
         */
        strcat(target_path, "/c");
        strcat(COMMAND_CD, CD_URL);
        strcat(COMMAND_CD, " && gcc ");
        strcat(COMMAND_CD, filename);
        strcat(COMMAND_CD, ".");
        strcat(COMMAND_CD, suffix);
        strcat(COMMAND_CD, " -std=c11 -o ");
        strcat(COMMAND_CD, target_path);
        strcat(COMMAND_CD, "/");
        strcat(COMMAND_CD, name);
        strcat(COMMAND_CD, " && ");
        strcat(COMMAND_CD, target_path);
        strcat(COMMAND_CD, "/");
        strcat(COMMAND_CD, name);
        system(COMMAND_CD);
    }
    else if (strcmp(suffix, "cpp") == 0)
    {
        /**
         * cd /Users/zhanggj/Downloads/CLionProjects/multilingual-data-structure-algorithm/multilingual/cpp &&
         * g++ hello_c++.cpp -std=c++11 -o /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/target/cpp/hello_c++ &&
         * /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/target/cpp/hello_c++
         */
        strcat(target_path, "/cpp");
        strcat(COMMAND_CD, CD_URL);
        strcat(COMMAND_CD, " && g++ ");
        strcat(COMMAND_CD, filename);
        strcat(COMMAND_CD, ".");
        strcat(COMMAND_CD, suffix);
        strcat(COMMAND_CD, " -std=c++11 -o ");
        strcat(COMMAND_CD, target_path);
        strcat(COMMAND_CD, "/");
        strcat(COMMAND_CD, name);
        strcat(COMMAND_CD, " && ");
        strcat(COMMAND_CD, target_path);
        strcat(COMMAND_CD, "/");
        strcat(COMMAND_CD, name);
        system(COMMAND_CD);
    }
    else if (strcmp(suffix, "java") == 0)
    {
        /**
         * cd /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/data_structure/array &&
         * javac /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/data_structure/array/Array.java
         * -d /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/target/java &&
         * cd /Users/zhanggj/Downloads/vscode-projects/multilingual-data-structure-algorithm/target/java &&
         * java Array
         */
        strcat(target_path, "/java");
        strcat(COMMAND_CD, CD_URL);
        strcat(COMMAND_CD, " && javac ");
        strcat(COMMAND_CD, FULL_URL);
        strcat(COMMAND_CD, " -d ");
        strcat(COMMAND_CD, target_path);
        strcat(COMMAND_CD, " && cd ");
        strcat(COMMAND_CD, target_path);
        strcat(COMMAND_CD, " && java ");
        strcat(COMMAND_CD, name);
        system(COMMAND_CD);
    }
    else if (strcmp(suffix, "py") == 0)
    {
        /**
         * cd /Users/zhanggj/Downloads/CLionProjects/multilingual-data-structure-algorithm/multilingual/python &&
         * python3 hello_python.py
         */
        char *s = argv[1];
        strcat(target_path, "/py");
        strcat(COMMAND_CD, CD_URL);
        strcat(COMMAND_CD, " && python3 ");
        strcat(COMMAND_CD, filename);
        strcat(COMMAND_CD, ".");
        strcat(COMMAND_CD, suffix);
        system(COMMAND_CD);
    }
    else
    {
        printf("Arguments error!");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void search_file(char *target_file, char *file_dir, unsigned long file_dir_length)
{
    struct dirent *ptr;
    struct stat st;
    DIR *dir = opendir(file_dir);
    while (dir != NULL && (ptr = readdir(dir)) != NULL)
    {
        if (FULL_URL[0] != '\0')
        {
            break;
        }
        char *ptr_name = ptr->d_name;
        if (strcmp(ptr_name, ".") == 0 || strcmp(ptr_name, "..") == 0)
        {
            continue;
        }
        char url[300];
        strcpy(url, file_dir);
        char *last_char = file_dir + (file_dir_length - 1);
        if (strcmp(last_char, "/") != 0)
        {
            strcat(url, "/");
        }
        strcat(url, ptr_name);
        stat(url, &st);
        if (S_ISDIR(st.st_mode))
        {
            search_file(target_file, url, strlen(url));
        }
        else
        {
            if (strcmp(ptr_name, target_file) == 0)
            {
                str_copy(FULL_URL, url);
                str_copy(CD_URL, file_dir);
            }
        }
    }
    if (dir != NULL)
    {
        closedir(dir);
    }
}

void split(char *src, const char *separator, char **dest, int *num)
{
    char *pNext;
    int count = 0;
    if (src == NULL || strlen(src) == 0)
        return;
    if (separator == NULL || strlen(separator) == 0)
        return;
    pNext = strtok(src, separator);
    while (pNext != NULL)
    {
        *dest++ = pNext;
        ++count;
        pNext = strtok(NULL, separator);
    }
    *num = count;
}

unsigned int str_length(const char *str)
{
    const char *start = str;
    while (*str)
    {
        str++;
    }
    return str - start;
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

void create_target(char *project_url)
{
    char base1[300] = "";
    char base2[300] = "";
    char base3[300] = "";
    char base4[300] = "";
    str_copy(base4, project_url);
    strcat(base4, "/target");
    mkdir(base4, 0777);
    str_copy(base1, base4);
    str_copy(base2, base4);
    str_copy(base3, base4);
    strcat(base1, "/java");
    strcat(base2, "/c");
    strcat(base3, "/cpp");
    mkdir(base1, 0777);
    mkdir(base2, 0777);
    mkdir(base3, 0777);
}
