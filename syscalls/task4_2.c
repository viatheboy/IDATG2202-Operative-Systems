#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* fork */
#include <sys/wait.h> /* waitpid */
#include <sys/types.h> /* pid_t */
/* Note: pid_t is probably just an int, but it might be different
kind of ints on different platforms, so using pid_t instead of
int helps makes the code more platform-independent
*/


void process(int number, int time) {
    printf("Process %d is running\n", number);
    sleep(time);
    printf("Prosess %d ran for %d seconds\n", number, time);
}


int main(void) {
    pid_t pid, pid2;

    pid = fork();
    pid2 = getpid();

    if (pid == 0) {
        process(0, 1);
    } else {
        process(2, 3);
    }

    waitpid(pid, NULL, 0);

    if (pid == 0) {
        process(4, 3);
    } else {
        process(1, 2);
    }

    return 0;
}