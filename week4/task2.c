#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void forkloop() {
    for (int i = 0; i < 5; i++) {
        fork();
    }
    sleep(5);
}

int main() {
    forkloop();
    return 0;
}