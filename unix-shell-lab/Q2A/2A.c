#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {

        struct stat st;

        if (argc < 2) {
                printf("Usage %s <filename>\n", argv[0]);
                return 0;
        }
        if ((stat(argv[1], &st)) == -1) {
               printf("File cannot be opened\n\n");
               return 0;
        }

        printf("File statistics are:\n\n");
        printf("Mode:\t\t\t%o\n", st.st_mode &07777);
        printf("Inode:\t\t\t%ld\n", st.st_ino);
        printf("Number of links:\t%ld\n", st.st_nlink);
        printf("Block Size:\t\t%ld\n", st.st_blksize);
        printf("Size:\t\t\t%ld\n", st.st_size);
        printf("User ID:\t\t%d\n", st.st_uid);
        printf("Group ID:\t\t%d\n", st.st_gid);
        printf("Last Modified Time:\t%s\n", ctime(&st.st_mtime));
        printf("Access Time:\t\t%s\n", ctime(&st.st_atime));

        return 0;

}
