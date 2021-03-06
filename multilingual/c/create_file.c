/**
 * @Author ZhangGJ
 * @Date 2021/08/28 07:28
 */
#include <stdio.h>

int main(void)
{
    /**
     *  "r"	以“只读”方式打开文件。只允许读取，不允许写入。文件必须存在，否则打开失败。
        "w"	以“写入”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
        "a"	以“追加”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
        "r+"	以“读写”方式打开文件。既可以读取也可以写入，也就是随意更新文件。文件必须存在，否则打开失败。
        "w+"	以“写入/更新”方式打开文件，相当于w和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
        "a+"	以“追加/更新”方式打开文件，相当于a和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
     */
    FILE *file;
    char *file_path = "/tmp/multilingual.conf";
    file = fopen(file_path, "a+");
    if (file == NULL)
    {
        printf("Create fail");
    }
    else
    {
        printf("Success");
        int x = 4;
        fprintf(file, "yes you are right ！\ny=4+%d", x);
        fclose(file);
    }
    return 0;
}
