#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define BUFFER_SIZE 128

int main()
{   
    char buf[BUFFER_SIZE];
    /* 清除脏数据 */
    memset(buf, 0, sizeof(buf));

    getcwd(buf, sizeof(buf) - 1);

    /* 打开当前进程的文件夹 */
    DIR * pDir = opendir(buf);
    if (pDir == NULL)
    {
        perror("opendir error");
        return 0;
    }

    struct stat statbuf;
    stat("./testDir.c", &statbuf);
    printf("statbuf.mode:%d\n\n", statbuf.st_mode);

    struct dirent * pdirent = NULL;
    while ((pdirent = readdir(pDir)) != NULL)
    {   
        if (pdirent->d_type == DT_REG)
        {
            printf("name:%s\td_type:%d\n", pdirent->d_name, pdirent->d_type);
        }
    }

    /* 关闭文件夹 */
    closedir(pDir);


    return 0;
}
