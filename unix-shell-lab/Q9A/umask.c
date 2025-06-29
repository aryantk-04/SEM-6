#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

        umask(0444);
        int fd = open("umask.txt", O_CREAT | O_RDWR, 0655);
        return 0;

}
