#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void forkfamily()
{
    pid_t pid;
    int n=10;

    if (fork() == 0){
        pid = getpid();
        printf("Hello from parent [%d - %d]\n", pid, n);
    }
    else{
        pid = getpid();
        printf("Hello from child [%d - %d]\n", pid, n);
    }
}

int main() {
    forkfamily();
    return 0;
}