//#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
//#include <unistd.h>
//#include<string.h>
extern int errno;


int main()
{
   int fd  = -1,check = -1, i = 0;
   fd = open("check.txt", | O_RDWR,0744);
    //char *c = (char *) calloc(100, sizeof(char));

   if (fd == -1)
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno); 
         
        // print program detail "Success or failure"
        perror("Program");                 
    }
  /*  printf("Calling Write\n");
    check = write(fd,"ABhishek1",strlen("ABhishek1"));
    printf("%d",check);
    int check1;
    check1 */


}
