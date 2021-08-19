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

// char *search_file(char *target_file, char file_or_dir);

int main(int argc, char *argv[])
{
    FILE *file;

    char compiler_url[100];

    if ((access(URL_FILENAME, F_OK) == -1))
    {
        file = fopen(URL_FILENAME, "w");
        if (file == NULL)
        {
            printf("Open %s error!\n", URL_FILENAME);
        }

        char *target_file;

        struct dirent *ptr;

        DIR *dir = opendir(ROOT_DIR);
        while ((ptr = readdir(dir)) != NULL)
        {
            if (strcmp(ptr->d_name, PROJECT_NAME) == 0)
            {
                printf("");
            }
        }
    }
    else
    {
        file = fopen(URL_FILENAME, "r");
        while (fgets(compiler_url, 100, file) != NULL)
            ;
        printf("URL: %s", compiler_url);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

// char *search_file(char *target_file, char file_or_dir)
// {
//     fread(target_file,)
// }