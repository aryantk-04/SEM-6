#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

        if (argc < 2) {
                printf("Usage %s <filename>\n", argv[0]);
                return 0;
        }

        if (access(argv[1], F_OK) == 0) {
                printf("The file %s can be accessed and executed.\n", argv[1]);
        }

        else {
                printf("The file %s cannot be accessed and executed.\n", argv[1]);
        }

        return 0;

}
