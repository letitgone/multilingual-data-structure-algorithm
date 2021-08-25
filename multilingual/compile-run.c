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

char *file_suffix(char *filename);

int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     printf("Arguments error!");
    //     return EXIT_FAILURE;
    // }

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

    fclose(file);
    return EXIT_SUCCESS;
}

char *search_file(char *target_file, char *file_dir)
{

    struct dirent *ptr;

    char *multilingual_url = NULL;

    struct stat st;

    DIR *dir = opendir(file_dir);
    while ((ptr = readdir(dir)) != NULL)
    {
        char *ptr_name = ptr->d_name;
        if (strcmp(ptr_name, ".") == 0 || strcmp(ptr_name, "..") == 0)
        {
            continue;
        }
        strcat(file_dir, ptr_name);
        stat(file_dir, &st);
        if (!S_ISDIR(st.st_mode))
        {
            continue;
        }
        printf("d_name : %s\n", ptr_name);
        if (strcmp(ptr_name, target_file) == 0)
        {
            multilingual_url = file_dir;
            strcat(multilingual_url, target_file);
            return multilingual_url;
        }
        else
        {
            multilingual_url = file_dir;
            strcat(multilingual_url, ptr_name);
            return search_file(PROJECT_NAME, multilingual_url);
        }
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

// _Bool is_file(char *filename)
// {
    
//     int result;
//     result = _stat(filename, &buf);
//     if (_S_IFDIR & buf.st_mode)
//     {
//         printf("folder\n");
//     }
//     else if (_S_IFREG & buf.st_mode)
//     {
//         printf("file\n");
//     }

//     return 0;
// }