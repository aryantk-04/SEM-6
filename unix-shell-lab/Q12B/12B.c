#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

        char *env[] = {"USER = unknown", "PATH = /temp", NULL};
        if (fork() == 0) {
                printf("Custom Environment is:\n\n\n");
                execle("./child", "child", "myarg1", "myarg2", "myarg3", NULL, env);
        }
        wait(NULL);
        printf("\n\n\nSystem Default Environment is\n\n\n");
        execlp("./child", "child", "myarg1", "myarg2", NULL);

        return 0;

}
