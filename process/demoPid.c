#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t currentPid = getpid();
    pid_t parentPid = getppid();

    printf("currentPid:%d\n", currentPid);
    printf("parentPid:%d\n", parentPid);

    while (1)
    {
        printf("hello world\n");

        sleep(3);
    }

    return 0;
}