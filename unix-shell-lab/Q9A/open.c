#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

        int fd = open("file.txt", O_CREAT | O_RDWR, 0644);
        return 0;

}
