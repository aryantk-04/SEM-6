#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wait.h>

int main() {

        if (fork() == 0) {
                printf("Child process (PID: %d) is running...\n", getpid());
                execl("textinterpreter", "test", "myarg1", "myarg2", (char *)0);
        }

        wait(NULL);

        return 0;

}
