#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("/dev/random", "r");
    FILE *fw = fopen("./ex1.txt", "w");

    char *file = (char *) malloc(sizeof(char));
    char *s = fgets(file, 20, f);
    fprintf(fw, s);
    fclose(fw);
    return 0;
};
