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


int main()
{
    
    int ret = truncate("./heiheihei.c", 20);
    if (ret == -1)
    {
        perror("truncate error");
        return 0;
    }


    return 0;
}