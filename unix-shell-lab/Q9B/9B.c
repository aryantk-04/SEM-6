#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char * argv[]) {

        if (argc < 2) {
                printf("Usage %s <filename>\n", argv[0]);
                return 0;
        }

        int fd = open(argv[1], O_RDWR);

        struct stat st;
        fstat(fd, &st);

        int n = st.st_size;

        char buf[20];

        printf("First 20 characters of the file are:\n");
        lseek(fd, 0, SEEK_SET);
        read(fd, buf, 20);
        buf[20] = '\0';
        printf("%s\n\n", buf);

        printf("20 characters from 10th byte is:\n");
        lseek(fd, 10, SEEK_SET);
        read(fd, buf, 20);
        buf[20] = '\0';
        printf("%s\n\n", buf);

        printf("20 characters, from 10 bytes, from current position is:\n");
        lseek(fd, 10, SEEK_CUR);
        read(fd, buf, 20);
        buf[20] = '\0';
        printf("%s\n\n", buf);

        printf("Size of file is: %d\n\n", n);

        return 0;

}
