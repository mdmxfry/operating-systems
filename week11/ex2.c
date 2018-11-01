#include <stdio.h>
#include <zconf.h>
#include <string.h>

int main() {
    int C_SIZE = 1024;
    char buffer[C_SIZE];
    char source[] = "Hello";

    FILE *fp = fopen("ex2.txt", "w+");
    setvbuf(fp, buffer, _IOLBF, C_SIZE);

    for (int i = 0; i < strlen(source); i++) {
        sleep(1);
        fputs("H", fp);
    }

    fputs("\n", fp);

    rewind(fp);
    fclose(fp);

    return 0;
}