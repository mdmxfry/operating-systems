// it works, but i\m not sure if i've done all right
#include <stdio.h>

int main() {
    char **s;
    char foo[] = "Hello World";
    char *foo_pointer = foo;

    s = &foo_pointer;
    printf("s is %s\n", *s);

    s[0] = &foo;
    printf("s[0] is %s\n", s[0]);

    return 0;
}