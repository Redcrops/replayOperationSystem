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
        _exit(0);
    }
    if (pid == 0)
    {
        /* 休眠1S, 让出CPU. 目的是: 父进程的逻辑先执行完. */
        sleep(1);

        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process : childPid:%d, num:%d\n", childPid, num);

        /* 父进程 todo... */
        pid_t parentPid = getppid();
        printf("child process : parentPid:%d\n", parentPid);

        int childA = 666;
        // while (1)
        // {
        //     sleep(3);
        // }
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent precess : parentPid:%d, num:%d\n", parentPid, num);
        
        num += 100;
        printf("parent precess : parentPid:%d, num:%d\n", parentPid, num);

        /* 独立的地址空间 */
        // printf("parent process : childA:%d\n", childA);


        // while (1)
        // {
        //     sleep(3);
        // }
    }

    /* 父子进程都会到达这个地方 */
    printf("hello world\n");

    return 0;
}