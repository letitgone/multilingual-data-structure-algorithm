#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define URL_CONFIG "/tmp/multilingual.conf"

#define PROJECT_NAME "multilingual-data-structure-algorithm"

char *search_file(char *target_file, char *file_dir, int file_dir_length);

char *file_suffix(char *filename);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Arguments error!");
        return EXIT_FAILURE;
    }
    FILE *file = NULL;
    char compiler_url[100];
    if ((access(URL_CONFIG, F_OK) == -1))
    {
        char project_url[100];
        scanf("Please enter project file url: %s", project_url);
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
        char *multilingual_url = search_file("argc[1]", project_url, strlen(project_url));
        if (multilingual_url == NULL)
        {
            printf("File error!");
            return EXIT_FAILURE;
        }

        file = fopen(multilingual_url, "w");
        if (file == NULL)
        {
            printf("Open %s error!\n", "URL_FILENAME");
        }
        printf("");
    }
    else
    {
        file = fopen("URL_FILENAME", "r");
        while (fgets(compiler_url, 100, file) != NULL)
        {
        }
        printf("URL: %s", compiler_url);
        if (compiler_url[0] != '\0')
        {
            char *file_name = argv[1];
            char *result_url = search_file(file_name, compiler_url, 1);
            char *command_cd = strcat("cd ", result_url);
            system(command_cd);
            char *suffix = file_suffix(file_name);
            char *target_path = strcat(compiler_url, "/target");
            if (strcmp(suffix, "c"))
            {
                char *c_command = "gcc $fileName -std=c11 -o target_path /c/$fileNameWithoutExt";
            }
            else if (strcmp(suffix, "cpp"))
            {
                char *cpp_command = "";
            }
            else if (strcmp(suffix, "java"))
            {
                char *java_command = "";
            }
            else if (strcmp(suffix, "py"))
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
        }
    }
    return EXIT_SUCCESS;
}

char *search_file(char *target_file, char *file_dir, int file_dir_length)
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
        char ss[256] = "";
        strcpy(ss, file_dir);
        char *last_char = file_dir + (file_dir_length - 1);
        if (strcmp(last_char, "/") != 0)
        {
            strcat(ss, "/");
        }
        strcat(ss, ptr_name);
        stat(ss, &st);
        if (!S_ISDIR(st.st_mode))
        {
            continue;
        }
        printf("d_name : %s\n", ptr_name);
        if (strcmp(ptr_name, target_file) == 0)
        {
            return (char *) ss;
        }
        else
        {
            char *result = search_file(PROJECT_NAME, ss, 1);
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
