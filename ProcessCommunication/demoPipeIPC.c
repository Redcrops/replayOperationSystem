#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define PIPE_SIZE 2

int main()
{
    int pipefd[PIPE_SIZE];
    /* 清除脏数据 */
    memset(pipefd, 0, sizeof(int) * PIPE_SIZE);

    /* 创建管道 */
    pipe(pipefd);

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        exit(-1);
    }

    if (pid == 0)
    {
        /* 关闭子进程的读端 */
        close(pipefd[0]);

        /* 子进程 写 */
        int num = 200;
        write(pipefd[1], (void *)&num, sizeof(int));

        #if 0
        /* 这个用法不对. */
        int childReadNum = 0;
        read(pipefd[0], (void *)&childReadNum, sizeof(childReadNum));
        printf("child process : childReadNum:%d\n", childReadNum);
        #endif

        /* 关闭写端 */
        close(pipefd[1]);
    }
    else if (pid > 0)
    {
        sleep(1);

        /* 关闭写端 */
        close(pipefd[1]);

        /* 父进程 读 */
        int readNum = 0;
        read(pipefd[0], (void *)&readNum, sizeof(int));

        printf("parent process : readNum:%d\n", readNum);

        /* 关闭读端 */
        close(pipefd[0]);
    }
}
