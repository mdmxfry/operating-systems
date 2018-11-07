#include <stdio.h>
#include <string.h>

/* HOW TO USE:
 * emulates command tee in POSIX
 * Example:
 * echo hi | ./ex2 -a file1.txt file2.txt fileN.txt
 * */

char *read(){
    char *buffer = NULL;
    unsigned int len;

    getline(&buffer, &len, stdin);
    puts(buffer);
    return buffer;
}

int main(int argc, char *argv[]) {
    char s[2] = "w";
    char *buffer = read();

    printf("%s", buffer);
    if (argc == 1){
        return 0;
    }
    if (argc >= 2){
        if (strncmp(argv[1], "-a", 2) == 0){
            strcpy(s, "a");
        }

        for(int ct=2; ct<argc; ct++){
            FILE *f = fopen(argv[ct], s);
            fprintf(f, "%s", buffer);
        }
    }
    return 0;
}