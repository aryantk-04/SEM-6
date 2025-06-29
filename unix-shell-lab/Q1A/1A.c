#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

        if (argc < 2) {
                printf("Usage %s <filename>\n", argv[0]);
                return 0;
        }

        int fd = open(argv[1], O_RDWR);

        struct stat st;
        stat(argv[1], &st);

        int n = st.st_size;
        printf("Length of file in bytes is %d\n", n);

        char buf[2];

        int pos = lseek(fd, 0, SEEK_END);

        while (--pos >= 0) {

                lseek(fd, pos, SEEK_SET);
                read(fd, buf, 1);
                buf[1] = '\0';
                printf("%s", buf);

        }

        printf("\n");

        return 0;

}
