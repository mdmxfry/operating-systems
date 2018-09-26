#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//SIGINT

void sig_handler(int signo)
{
    if (signo == SIGINT)
        printf("Received SIGINT\n");
    else if (signo == SIGKILL)
        printf("Received SIGKILL\n");
    else if (signo == SIGSTOP)
        printf("Received SIGSTOP\n");
    else if (signo == SIGUSR1)
        printf("Received SIGUSR1\n");

}

int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch signal\n");

    while(1)
        sleep(1);
    return 0;
}