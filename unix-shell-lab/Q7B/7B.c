#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

        if (argc < 3) {
                printf("Usage %s <src> <dest>\n", argv[0]);
                return 0;
        }

        int src = open(argv[1], O_RDONLY);
        int dest = open(argv[2], O_CREAT | O_RDWR, 0777);

        struct stat st;
        stat(argv[1], &st);
        int n = st.st_size;
        char buf[n];

        read(src, buf, n);
        write(dest, buf, n);

        return 0;

}
