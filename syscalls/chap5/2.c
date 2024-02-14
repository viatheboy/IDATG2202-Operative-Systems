#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
	// child: redirect standard output to a file
	close(STDOUT_FILENO);
	open("./2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

    pid_t pid = fork();

	// now exec "wc"...
    if (pid == 0) {
        
    }
    char *myargs[3];
    myargs[0] = strdup("wc");   // program: "wc" (word count)
    myargs[1] = strdup("2.c"); // argument: file to count
    myargs[2] = NULL;           // marks end of array
    execvp(myargs[0], myargs);  // runs word count
    // parent goes down this path (original process)
    int wc = wait(NULL);
	assert(wc >= 0);
    return 0;
}