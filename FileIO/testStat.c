#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 64

void get_file_time(__time_t st_time)
{
    struct tm* info;
	info=localtime(&(st_time));
	printf("%02d %02d %02d:%02d\n",info->tm_mon+1,\
			info->tm_mday,info->tm_hour,info->tm_min);
}

int main()
{
    struct stat bufStat;
    stat("./testCopy.c", &bufStat);

    printf("mode:%d\n", bufStat.st_mode);
    printf("st_size:%ld\n", bufStat.st_size);

    /* 宏函数来判断文件类型 */
    int ret = S_ISDIR(bufStat.st_mode);
    printf("ret:%d\n", ret);

    // /* 最后一次访问时间 */
    get_file_time(bufStat.st_atime);
    // /* 最后一次修改时间 */
    // get_file_time(bufStat.st_mtime);
    // /* 最后一次改变时间(属性)*/
    // get_file_time(bufStat.st_ctime);

/* 检测配置文件是否更新 */
    // system("md5sum testStat.c");
    
#if 0
    FILE *pfd = popen("md5sum testStat.c", "r");
    if (pfd == NULL)
    {
        perror("popen error");
        return 0;
    }

    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));
    fread(buf, sizeof(buf) - 1, 1, pfd);

    /* 下面使用正则来过滤 */
    printf("buf:%s\n", buf);

    pclose(pfd);
#endif

    return 0;   
}