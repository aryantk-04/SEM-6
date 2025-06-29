#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

        int pid1 = fork();

        if (pid1 == 0) {
                printf("Child process (PID: %d) running...\n", getpid());
                sleep(5);
                exit(0);
        }

        int pid2 = fork();

        if (pid2 == 0) {
                printf("Child process (PID: %d) running...\n", getpid());
                sleep(10);
                exit(0);
        }

        wait(NULL);
        printf("First wait\n");

        waitpid(pid2, NULL, 0);;
        printf("Second wait\n");

        return 0;

}
