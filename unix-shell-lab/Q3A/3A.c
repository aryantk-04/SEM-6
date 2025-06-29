#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

int main() {

        struct dirent *dir;
        DIR *dp = opendir(".");

        while ((dir = readdir(dp)) != NULL) {

                int fd = open(dir -> d_name, O_RDWR);
                int n = lseek(fd, 0, SEEK_END);
                if (!n) {
                        unlink(dir -> d_name);
                }

        }

        return 0;

}
