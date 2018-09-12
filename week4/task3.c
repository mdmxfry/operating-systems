#include <stdlib.h>
#include <stdio.h>

int system(const char *command);

int main(){
    char cmd [100];
    scanf("%s", &cmd);
    system(cmd);
    return 0;
}