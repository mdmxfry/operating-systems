#include <stdio.h>
#include <zconf.h>
#include <string.h>

int main() {
    int C_SIZE = 64;
    char buffer[C_SIZE];
    char source[] = "Hello";

    setvbuf(stdout, buffer, _IOLBF, C_SIZE);

    for (int i = 0; i < strlen(source); i++) {
        sleep(1);
        printf("H");
    }

    printf("\n");

    return 0;
}