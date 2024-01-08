#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
    int num = 100;

    /* 创建一个子进程 */
    pid_t pid = fork();
    /* 创建完子进程后, 父进程不会自杀. */

    if (pid < 0)
    {
        perror("fork error");
        return 0;
    }
    if (pid == 0)
    {
        /* 休眠1S, 让出CPU. 目的是: 父进程的逻辑先执行完. */
        sleep(1);

        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process : childPid:%d, num:%d\n", childPid, num);

      
        // pid_t parentPid = getppid();
        // printf("child process : parentPid:%d\n", parentPid);
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent precess : parentPid:%d, num:%d\n", parentPid, num);
        
        num += 100;
        printf("parent precess : parentPid:%d, num:%d\n", parentPid, num);
    }

    return 0;
}