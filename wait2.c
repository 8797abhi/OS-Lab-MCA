#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
//#include<dos.h>
#define MAX_COUNT 2

void ChildProcess(char []);

void main(void)
{
    pid_t pid1,pid2,pid;		
    int status;
    int i;
    printf("PARENT %d \n",getpid());
    printf("\n\n\n*** Parent is about to fork process 1***\n\n\n");
    if((pid1 = fork()) <0)		//fork fails if return value is negative
    {
        printf("Failed to fork process 1\n");
        exit(1);
    }

    else if(pid1 == 0)			//first child process is born
        ChildProcess("First");
    
    //kill(pid1,SIGHUP);
    sleep(10);
    if((pid2 = fork()) < 0)	
    {	
            printf("Failed to fork process 2\n");
        exit(1);   
    }
    else if(pid2 == 0)				//second child process is born
        ChildProcess("Second");
       
    printf("\n\n\n*******Parent enters waiting status***************\n");
    pid = wait(&status);
   
    printf("\n\n\n*******Parent detects process %d was done*************\n", pid1);
    pid = wait(&status);

        //printf("*******Parent detects process %d is done**************\n", pid2);
    printf("*******Parent exits********\n");
    exit(0);
}


void ChildProcess(char *number)
{
    int i;
    printf("%s Child is running",number);
    printf("\n\nCHILD ID: %d",getpid());
    ab: printf("\n\n Do you wish to \n1. Kill the Parent\n\n2. Kill the child ?\n\n3. Do Nothing\n\nInput:\t");
    scanf("%d",&i);

    if(1 == i)
    {
	kill(getppid(),9);
    }
    else if(2 == i)		//menu driven program to kill either child, parent or normal execution of 					the program
    {
	kill(getpid(),9);
    }				//if first child is killed, second is forked, and if second child is 					killed, parent excecutes normally
    else if( 3 == i)
    {
	goto bc;		//if parent is killed, the program terminates abruptly
    }
    else
    {
	printf("\n\nSorry Wrong Choice, please try again!");
	goto ab;
    }
    bc: printf("\n\nChild %s is now exiting\n\n",number);
    exit(0);
}

