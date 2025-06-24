#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
        int src = open("src.txt", O_RDONLY);
        int dest = open("dest.txt", O_WRONLY);
        char buf[100];
        int pos = lseek(src, 0, SEEK_END);

        while (--pos >= 0) {
                lseek(src, pos, SEEK_SET);
                read(src, buf, 1);
                write(dest, buf, 1);
        }
        return 0;
}
