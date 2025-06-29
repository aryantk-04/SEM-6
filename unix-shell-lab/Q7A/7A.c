#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <setjmp.h>

int globval = 1;
jmp_buf jmpbuffer;

int main() {

        register int regval = 1;
        static int statval = 1;
        volatile int volval = 1;

        printf("Before longjmp\n");
        printf("Global\tStat\tReg\tVolatile\n");
        printf("%d\t%d\t%d\t%d\n", globval, statval, regval, volval);

        while (setjmp(jmpbuffer) != 0) {
                printf("After longjmp\n");
                printf("Global\tStat\tReg\tVolatile\n");
                printf("%d\t%d\t%d\t%d\n", globval, statval, regval, volval);
                return 0;
        }

        globval = 10;
        regval = 10;
        statval = 10;
        volval = 10;

        longjmp(jmpbuffer, 1);


        return 0;
}
