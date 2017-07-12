#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    for (int i = 0; i < 3; i++) {
        fork();
        printf("pid %d forked, i=%d, ppid %d", getpid(), i, getppid());
        printf("-");
        printf("\n");
    }

    printf("pid %d wait\n", getpid());

    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("pid %d teminated\n", getpid());
    return 0;
}
