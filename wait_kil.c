#include<stdio.h>
#include<sys/wait.h>
#include <unistd.h>
#include<sys/types.h>

int main()
{
    pid_t p;
    p = fork();
    if( p < 0 ) //fail
    {
        exit(0);
    }
    if ( p == 0) // child
    {
        printf("Child Created");
        
    }
    else
    {
        printf("Parent Created");
       wait(NULL) 
    }
}