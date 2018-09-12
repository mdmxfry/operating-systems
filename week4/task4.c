#include <stdlib.h>
#include <stdio.h>

int system(const char *command);

int main() {
    int pid;
    int counter;
    char input[100];
    printf("Control+C to leave");
    while (input != 'quit') {
        printf("> ");
        scanf(" %[^\t\n]s", input);
        pid = fork();
        if(pid == 0)
            scanf(" %[^\t\n]s", input);
        else
            system(input);
    }
    return 0;
}