#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <utime.h>

int main() {

        struct stat st;
        struct utimbuf tt;

        stat("src.txt", &st);
        tt.actime = st.st_atime;
        tt.modtime = st.st_mtime;
        utime("dest.txt", &tt);

        return 0;

}
