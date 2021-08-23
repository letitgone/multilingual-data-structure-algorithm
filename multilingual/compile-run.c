#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#define URL_FILENAME "/Users/zhanggj/Desktop/multilingual.conf"

#define ROOT_DIR "/"

#define PROJECT_NAME "multilingual-data-structure-algorithm"

char *search_file(char *target_file, char *file_dir);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Arguments error!");
        return 1;
    }

    FILE *file;

    char compiler_url[100];

    if ((access(URL_FILENAME, F_OK) == -1))
    {
        char *multilingual_url = search_file(PROJECT_NAME, ROOT_DIR);
        file = fopen(multilingual_url, "w");
        if (file == NULL)
        {
            printf("Open %s error!\n", URL_FILENAME);
        }
        printf("");
    }
    else
    {
        file = fopen(URL_FILENAME, "r");
        while (fgets(compiler_url, 100, file) != NULL)
        {
        }
        printf("URL: %s", compiler_url);
        if (compiler_url[0] != '\0')
        {
            char *file_name = argv[1];
            char *result_url = search_file(file_name, compiler_url);
            char *command_cd = strcat("cd ", result_url);
            system(command_cd);
            strtok(file_name, ".");
        }
        else
        {
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

char *search_file(char *target_file, char *file_dir)
{

    struct dirent *ptr;

    char *multilingual_url;

    DIR *dir = opendir(file_dir);
    while ((ptr = readdir(dir)) != NULL)
    {
        if (strcmp(ptr->d_name, target_file) == 0)
        {
            multilingual_url = file_dir;
            strcat(multilingual_url, "/");
            strcat(multilingual_url, target_file);
            return multilingual_url;
        }
        else
        {
            multilingual_url = file_dir;
            strcat(multilingual_url, "/");
            strcat(multilingual_url, ptr->d_name);
            return search_file(PROJECT_NAME, multilingual_url);
        }
    }
    return NULL;
}