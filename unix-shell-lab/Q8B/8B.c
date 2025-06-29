#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

        if (fork() == 0) {
                printf("Child process (PID: %d) running...\n", getpid());
                execl("./child", "child", argv[1], (char *)NULL);
        }

        wait(NULL);
        printf("Parent process has waited for child to execute\n\n");

        return 0;

}
