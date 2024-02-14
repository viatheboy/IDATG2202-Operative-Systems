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
    pid_t rc[6];      //return code -- pid_t er bare et annet navn på en int
    
    rc[0] = fork();
    if (rc[0] == 0) {
        process(0,1);
        exit(0);
    }
    rc[2] = fork();
    if (rc[2] == 0) {
        process(2,3);
        exit(0);
    }

    waitpid(rc[0], NULL, 0);
    rc[1] = fork();
    if (rc[1] == 0) {
        process(1, 2);
        exit(0);
    }
    rc[4] = fork();
    if (rc[4] == 0) {
        process(4, 3);
        exit(0);
    }

    waitpid(rc[1], NULL, 0);
    rc[3] = fork();
    if(rc[3] == 0) {
        process(3, 2);
        exit(0);
    }

    waitpid(rc[4], NULL, 0);
    rc[5] = fork();
    if (rc[5] == 0) {
        process(5,3);
        exit(0);
    }

    waitpid(rc[5], NULL, 0);
    printf("Program gjennomført suksessfult.\n");


    return 0;
}