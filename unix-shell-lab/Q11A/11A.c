#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

        int fd1 = open("file.txt", O_CREAT | O_RDWR, 0755);

        int fd2 = dup(fd1);

        int fd3 = dup2(fd1, 10);

        write(fd1, "Written by file descriptor 1. ", 30);
        printf("%d\n\n", fd1);

        write(fd2, "Written by file descriptor 4. ", 30);
        printf("%d\n\n", fd2);

        write(fd3, "Written by file descriptor 10.", 30);
        printf("%d\n\n", fd3);

        return 0;

}
