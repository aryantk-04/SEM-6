#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

        for (int i = 0; i < argc; i++) {
                printf("argv[%d] = %s\n", i, argv[i]);
        }

        return 0;

}
