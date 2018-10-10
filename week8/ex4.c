#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    struct rusage mem_fill;
    for (int i = 0; i < 10; i++) {
        void *m = malloc(10485760);

        memset(m, 0, 10485760);
        getrusage(RUSAGE_SELF, &mem_fill);
        printf("Usage=%ld\n", mem_fill.ru_maxrss);
        sleep(1);
    }
    return 0;
}
