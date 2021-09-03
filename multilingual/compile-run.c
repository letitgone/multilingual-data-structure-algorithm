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

char *file_suffix(char *filename);

unsigned int str_length(const char *str);

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
        char command_cd[300] = "cd ";
        strcat(command_cd, file_url);
        system(command_cd);
        char *suffix = file_suffix(filename);
        char *target_path = strcat(project_url, "target");
        if (strcmp(suffix, "c") != 0)
        {
            char *c_command = "gcc $fileName -std=c11 -o target_path /c/$fileNameWithoutExt";
        }
        else if (strcmp(suffix, "cpp") != 0)
        {
            char *cpp_command = "";
        }
        else if (strcmp(suffix, "java") != 0)
        {
            char *java_command = "";
        }
        else if (strcmp(suffix, "py") != 0)
        {
            char *py_command = "";
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
        char url[500];
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
            char *result = search_file(target_file, url, strlen(url));
            if (result == NULL)
            {
                continue;
            }
            else
            {
                return result;
            }
        }
    }
    if (dir != NULL)
    {
        closedir(dir);
    }
    return NULL;
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

unsigned int str_length(const char *str)
{
    const char *start = str;
    while (*str)
    {
        str++;
    }
    return str - start;
}