#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
   char buff[5];
   if(argc != 2) {
      printf("Need an argument!\n");
      exit(1);
   }
   strcpy(buff, argv[1]);
   printf("\nYou typed [%s]\n\n", buff);
   return(0);
}
