#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int s) {

        printf("Sig Int Count: %d\n", s);
        struct sigaction sa = {0};
        sa.sa_handler = SIG_DFL;
        sigaction(SIGINT, &sa, NULL);

}

int main() {

        struct sigaction sa = {0};
        sa.sa_handler = handler;
        sigaction(SIGINT, &sa, NULL);

        while (1) {
                printf("Press Ctrl + C twice to pause\n");
                pause();
        }

        return 0;

}
