#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void task1() {
    int p_array[2];
    pipe(p_array);
    char string[] = "Я строка простая";
    char readbuffer[sizeof(string)];

    // Write to the buffer with pipe[0]
    write(p_array[1], string, sizeof(string));

    // Read from the buffer with pipe[1]
    read(p_array[0], readbuffer, sizeof(readbuffer));
    printf("%s\n", readbuffer);

    close(p_array[0]);
    close(p_array[1]);
}

int main () {
    task1();
    return 0;
}