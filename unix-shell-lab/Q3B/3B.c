#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>

int main() {

        struct dirent *dir;
        DIR *dp = opendir(".");
        struct stat st;

        while ((dir = readdir(dp))) {
                stat(dir -> d_name, &st);
                printf("Name:\t\t\t%s\n", dir -> d_name);
                printf("Mode:\t\t\t%o\n", st.st_mode &0777);
                printf("Inode:\t\t\t%ld\n", st.st_ino);
                printf("Last Modified Time\t%s\n", ctime(&st.st_mtime));
                printf("Access Time\t\t%s\n", ctime(&st.st_atime));
                printf("Group ID\t\t%d\n", st.st_gid);
                printf("Owner ID\t\t%d\n\n\n\n", st.st_uid);
        }

        return 0;

}
