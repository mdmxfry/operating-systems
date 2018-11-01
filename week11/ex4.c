#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

#define EXIT_FAILURE 1

int main() {
    int f_status;
    char * s_map;  /* source mmapped array of chars */
    char * d_map;  /* target mmapped array of chars */
    int fs;
    int fd;

    struct stat sb;

    fs = open("ex1.txt", 'rb');
    if (fs == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    f_status = fstat(fs, &sb);

    fd = open("ex1.memcpy.txt", 'wb');
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    ftruncate(fd, sb.st_size);

    s_map = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fs , 0);
    d_map = mmap(NULL, sb.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd , 0);
    memcpy(s_map, d_map, sb.st_size);

    if (munmap(s_map, sb.st_size) == -1) {
        perror("Error un-mmapping the file");
    }

    if (munmap(d_map, sb.st_size) == -1) {
        perror("Error un-mmapping the file");
    }

    close(fd);
    close(fs);

    return 0;
}