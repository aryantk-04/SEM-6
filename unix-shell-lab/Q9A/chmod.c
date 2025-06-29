#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
        open("chmod.txt", O_CREAT | O_RDWR, 0755);
        chmod("chmod.txt", 0777);
        return 0;
}
