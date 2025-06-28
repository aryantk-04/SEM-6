#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

        if (argc < 2) {
                printf("Usage %s <filename>\n", argv[0]);
                return 0;
        }

        int fd = open(argv[1], O_RDWR);

        struct stat st;
        stat(argv[1], &st);

        printf("5 fields are: \n");
        printf("Mode:\t\t\t%d\n", st.st_mode & 0777);
        printf("Inode:\t\t\t%ld\n", st.st_ino);
        printf("Size:\t\t\t%ld\n", st.st_size);
        printf("Block Size:\t\t%ld\n", st.st_blksize);
        printf("Number of Links:\t%ld\n", st.st_nlink);

        return 0;
}
