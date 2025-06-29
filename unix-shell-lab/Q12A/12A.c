#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

        if (fork() == 0) {
                printf("Child process (PID: %d) has started running\n", getpid());
        }
        else {
                printf("Parent process will sleep now, making child a zombie\n");
                sleep(30);
                wait(NULL);
                printf("Parent process has reaped the child process.\n");
        }
        return 0;

}
