#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
        int file = open("file.txt", O_RDWR);
        char buf[20];

        if (fork() == 0) {
                printf("Child Process (PID : %d) reads\n", getpid());
                read(file, buf, 5);
                buf[5] = '\0';
                printf("The contents are: %s\n", buf);
        }
        else {
                printf("Parent Process (PID : %d) reads\n", getpid());
                read(file, buf, 5);
                buf[5] = '\0';
                printf("The contents are: %s\n", buf);
        }
        return 0;
}
