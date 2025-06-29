#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

        if (argc < 5) {
                printf("Usage %s <hsrc> <hardlink> <src> <softlink>\n", argv[0]);
        }

        link(argv[1], argv[2]);
        printf("Hardlink Created\n");

        symlink(argv[3], argv[4]);
        printf("Softlink Created\n");

        return 0;

}
