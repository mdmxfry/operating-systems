#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void task5() {
    pid_t process_id;
    process_id = fork();

    if (process_id == 0) {
        while (1) {
            printf("%s\n", "Sono vivo");
            sleep(2);
        }
    } else {
        sleep(10);
        // send terminal signall
        kill(process_id, SIGTERM);
    }

}

int main(void)
{
    task5();
    return 0;
}