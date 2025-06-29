#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

        int fd1 = open("file.txt", O_RDWR);

        int fd2 = dup2(fd1, 10);

        struct stat st;
        stat("file.txt", &st);
        int n = st.st_size;

        printf("Enter number of bytes to append less than %d\n", n);
        scanf("%d", &n);

        char buf[n];

        read(fd1, buf, n);
        buf[n] = '\0';

        lseek(fd2, -1, SEEK_END);
        write(fd2, buf, n);

        return 0;

}
