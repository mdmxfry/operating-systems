#include <stdlib.h>
#include <stdio.h>

int system(const char *command);

int main(int argc,char* argv[]){
    int counter;

    execvp(argv[0], argv);

    return 0;
}