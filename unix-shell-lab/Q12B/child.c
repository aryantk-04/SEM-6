#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[]) {

        for (int i = 0; i < argc; i++) {
                printf("argv[%d] = %s\n", i, argv[i]);
        }

        for (int i = 0; envp[i]; i++) {
                printf("%s\n", envp[i]);
        }

        return 0;

}
