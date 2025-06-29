#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <syslog.h>

void create_daemon() {

        if (fork() > 0) {
                exit(0);
        }

        setsid();
        umask(0);
        chdir("/");

}

int main() {

        create_daemon();

        while (1) {
                openlog("daemon_ex",LOG_PID, LOG_DAEMON);
                syslog(LOG_NOTICE, "Daemon is running now...\n");
        }

        return 0;

}
