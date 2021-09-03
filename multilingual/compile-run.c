#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define URL_CONFIG "/tmp/multilingual.conf"

#define PROJECT_NAME "multilingual-data-structure-algorithm"

char *search_file(char *target_file, char *file_dir, unsigned long file_dir_length);

void split(char *src, const char *separator, char **dest, int *num);

unsigned int str_length(const char *str);

char COMMAND_CD[300] = "cd ";

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Arguments error!");
        return EXIT_FAILURE;
    }
    char *filename = argv[1];
    FILE *file = NULL;
    if ((access(URL_CONFIG, F_OK) == -1))
    {
        char project_url[100];
        printf("Please enter project file url: ");
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
        char *file_url;
        file_url = search_file(filename, project_url, str_length(project_url));
        if (file_url == NULL)
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
            strcat(target_path, "/c");
        }
        else if (strcmp(suffix, "cpp") == 0)
        {
            strcat(target_path, "/cpp");
        }
        else if (strcmp(suffix, "java") == 0)
        {
            strcat(target_path, "/java");
            strcat(COMMAND_CD, file_url);
            strcat(COMMAND_CD, " && javac ");
            strcat(COMMAND_CD, file_url);
            strcat(COMMAND_CD, " -d ");
            strcat(COMMAND_CD, target_path);
            strcat(COMMAND_CD, " && java ");
            strcat(COMMAND_CD, name);
//            cd file_url && javac file_url -d target_path && java name
        }
        else if (strcmp(suffix, "py") == 0)
        {
            strcat(target_path, "/py");
        }
        else
        {
            printf("Arguments error!");
            return EXIT_FAILURE;
        }
    }
    else
    {
//        file = fopen(URL_CONFIG, "r");
//        while (fgets(compiler_url, 100, file) != NULL)
//        {
//        }
//        printf("URL: %s", compiler_url);
//        if (compiler_url[0] != '\0')
//        {
//        }
//        else
//        {
//        }
    }
    return EXIT_SUCCESS;
}

char *search_file(char *target_file, char *file_dir, unsigned long file_dir_length)
{
    struct dirent *ptr;
    struct stat st;
    DIR *dir = opendir(file_dir);
    while (dir != NULL && (ptr = readdir(dir)) != NULL)
    {
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
        printf("d_name : %s\n", ptr_name);
        if (strcmp(ptr_name, target_file) == 0)
        {
            return url;
        }
        else
        {
            continue;
        }
    }
    if (dir != NULL)
    {
        closedir(dir);
    }
    return NULL;
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
