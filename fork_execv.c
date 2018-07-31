#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int g_val = 100;

int main(){
    int x = 10;
    char *name = NULL;
    pid_t PID;

    PID = fork();
	int choice;
char *const arg[4] ={"ls",NULL};
char *const arg1[5] ={"cp",NULL};



    if(PID < 0){
        printf("FORK Failed");
        exit(0);
    }
    if(PID == 0){ 
/* Child */


printf("\n1.Ls");
printf("\n2.CP");
printf("Enter CHoice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
	       execvp("lsss",arg);
break;
case 2:
	execvp("copy",
break;
default:
	printf("Invalid Choice");

}    }
    else{ /* Parent */
	wait(NULL);
       /* name = "Parent";
        x = x + 10;
        g_val = g_val + 100;
        printf("%s %d %d\n",name,x, g_val);
        printf("MY PID is %d\n", getpid());
        printf("MY Child PID is %d\n", PID);*/
    }
       //printf("%s %d %d\n",name,x, g_val);
        return 0;
}

