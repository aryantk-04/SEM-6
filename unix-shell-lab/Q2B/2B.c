#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>


int my_sys(const char *cm) {
        int pid = fork();
        if (pid == 0) {
                execl("/bin/sh", "sh", "-c", cm, (char *)NULL);
        }

        int status;
        if (pid > 0 && waitpid(pid, &status, 0) != -1 && WIFEXITED(status)) {
                return WEXITSTATUS(status);
        }
        return 0;
}

int main() {

        printf("List of files in the directory are: \n");
        my_sys("ls -li");
        return 0;
}
