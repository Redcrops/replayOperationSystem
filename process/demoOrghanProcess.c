#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <wait.h>


int main()
{
    #if 0
    printf("hello world\n");
    /* 当进程没有子进程的时候 */
    wait(NULL);
    printf("hello world\n");
    #endif

    #if 1
    int num = 100;
    /* 创建一个子进程 */
    pid_t pid = fork();
    /* 创建完子进程后, 父进程不会自杀. */

    if (pid < 0)
    {
        perror("fork error");
        _exit(0);
    }
    if (pid == 0)
    {
        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process : childPid:%d, num:%d\n", childPid, num);

        while (1)
        {
            /* 子进程sleep(120) */
            sleep(2);
            printf("orphan process\n");
        }        

        /* 进程退出 */
        int childState = 1;
        _exit(0);
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent precess : parentPid:%d, num:%d\n", parentPid, num);
    }
    printf("hello world\n");

    #endif
    return 0;
}

