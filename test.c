#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER 30

int main() {
    int fd = open("abc.txt", O_RDWR), n;
    char buffer[BUFFER];

    printf("File descriptor is %d\n", fd);
    if (fd == -1) {
        perror("Failed to open file");
        exit(1);
    }

    // Reading first 10 characters
    printf("\nReading first 10 characters:\n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    // Skipping 5 characters from the current position
    printf("\nSkipping 5 characters from current position:\n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    // Going to the 5th last character
    printf("\nGoing to 5th last character:\n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);

    // Going to the 3rd character
    printf("\nGoing to 3rd character:\n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 5);
    write(1, buffer, n);

    close(fd);
    return 0;
}
