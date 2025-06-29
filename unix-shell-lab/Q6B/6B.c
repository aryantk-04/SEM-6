#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char *argv[]) {

        if (argc < 2) {
                printf("Usage %s <filename>\n", argv[0]);
                return 0;
        }

        int fd = open(argv[1], O_RDWR);

        char buf[101] = {0};

        struct stat st;
        struct flock fl;

        fl.l_type = F_WRLCK;
        fl.l_whence = SEEK_END;
        fl.l_start = -100;
        fl.l_len = 100;

        printf("Press Enter to lock the region...\n");
        getchar();

        if (fcntl(fd, F_SETLK, &fl) == -1) {
                fcntl(fd, F_GETLK, &fl);
                printf("Region locked by process (PID: %d)...\n", fl.l_pid);
                return 0;
        }

        printf("Region Locked\n");

        lseek(fd, -50, SEEK_END);
        read(fd, buf, 50);
        printf("%s\n", buf);

        printf("Press Enter to Unlock...\n");
        getchar();

        fl.l_type = F_UNLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        fcntl(fd, F_SETLK, &fl);

        return 0;

}
