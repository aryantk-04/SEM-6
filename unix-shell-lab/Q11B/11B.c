#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {

        if (fork() == 0) {
                execl("./child", "child", argv[1], argv[2], (char *)NULL);
        }

        wait(NULL);

        return 0;

}
