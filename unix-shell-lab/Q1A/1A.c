#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

        struct stat st;

        if (argc < 3) {
                printf("Usage %s <src> <dest>\n", argv[0]);
                return 0;
        }

        int src = open(argv[1], O_RDONLY);
        if (src == -1) {
                printf("%s doesn't exist\n", argv[1]);
                return 0;
        }

        int dest = open(argv[2], O_CREAT | O_WRONLY, 0777);
        if (dest == -1) {
                printf("%s doesn't exist\n", argv[1]);
                return 0;
       
