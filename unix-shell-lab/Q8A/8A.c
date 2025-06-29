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

        struct stat st;
        stat(argv[1], &st);

        if (S_ISREG(st.st_mode)) {
                printf("This is is a regular file.\n");
        }
        else if (S_ISDIR(st.st_mode)) {
                printf("This is a directory.\n");
        }
        else if (S_ISSOCK(st.st_mode)) {
                printf("This is a socket.\n");
        }
        else if (S_ISFIFO(st.st_mode)) {
                printf("This is a FIFO pipe.\n");
        }
        else if (S_ISCHR(st.st_mode)) {
                printf("This is a character.\n");
        }
        else if (S_ISLNK(st.st_mode)) {
                printf("This is a link.\n");
        }
        else if (S_ISBLK(st.st_mode)) {
                printf("This is a block.\n");
        }
        else {
                printf("This is an unknown file type\n");
        }

        return 0;

}
