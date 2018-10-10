#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 10; i++) {
        void *kp = malloc(10485760);

        memset(kp, 0, 10485760);
        sleep(1);
        free(kp);
    }
    return 0;
}
