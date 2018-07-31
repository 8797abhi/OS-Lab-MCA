#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>

int main()
{
    pid_t new_pro;

    new_pro = fork();
    if(new_pro < 0)
    {
        printf("Fork Failure");
    }
    else if(new_pro > 0 )//parent
    {
        printf("Parent");
    }
    else //child
    {   
        printf("Child\n");
        char* argv[4];
    argv[0] = "top";
    //argv[1] = "-li";
    argv[1] = NULL;
    execvp(argv[0],argv);
    }

}