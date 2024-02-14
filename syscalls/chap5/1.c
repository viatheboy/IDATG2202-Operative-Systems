#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int x = 100;

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        x *= 4;
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        printf("my value of x is: %d\n", x);
    } else {
        x += 15;
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
        printf("my value of x is: %d\n", x);
    }

    printf("Her er x etter alt: %d\n", x);
    
    return 0;
}

