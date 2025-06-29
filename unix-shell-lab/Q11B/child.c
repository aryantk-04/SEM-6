#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

        printf("\n");
        printf("Sum = %d\n\n", ((atoi(argv[1])) + (atoi(argv[2]))));

        return 0;

}
