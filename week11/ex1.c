#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define EXIT_FAILURE 1

int main(){
    char source[] = "This was a good day";

    int result;
    int f_status;
    char *map;  /* mmapped array of chars */
    int fd;

    struct stat sb;

    fd = open("ex1.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    f_status = fstat(fd, &sb);

    result = lseek(fd, strlen(source) - 1, SEEK_SET);
    result = write(fd, "", 1);

    map = mmap(0, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd , 0);
    if (map == MAP_FAILED) {
        close(fd);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }

    int len = strlen(source);
    for (int i = 0; i < len; i++) {
        map[i] = source[i];
    }

    if (munmap(map, sb.st_size) == -1) {
        perror("Error un-mmapping the file");
    }

    close(fd);

    return 0;
}