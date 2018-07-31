//orphan processes may be generated

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    char *name = NULL;
    pid_t PID;
    PID = fork();
    if( PID < 0 )
    {
        printf(" Fork Failed ");
        exit(0);
    }
    if( PID == 0 )/*child*/
    {
        name = "child1";
        printf("\n\n%s \n",name);
        printf("My PID is %d\n",getpid());
        printf("My Parent PID is %d\n",getppid());

        PID = fork();
        if( PID < 0 )
        {
            printf(" Fork Failed ");
            exit(0);
        }
        if( PID == 0 )/*gcchild1*/
        {
            name = "grandchild1";
            printf("\n\n%s \n",name);
            printf("My PID is %d\n",getpid());
            printf("My Parent PID is %d",getppid());
        }
    }
    else/*parent*/
    {
        name = "parent";
        printf("\n\n%s \n",name);
        printf("My PID is %d\n",getpid());
        printf("My Parent PID is %d\n",getppid());

        PID = fork();
        if( PID < 0 )
        {
            printf(" Fork Failed ");
            exit(0);
        }
        if( PID == 0 )/*child2*/
        {
            name = "child2";
            printf("\n\n%s \n",name);
            printf("My PID is %d\n",getpid());
            printf("My Parent PID is %d\n",getppid());

            PID = fork();
            if( PID < 0 )
            {
                printf(" Fork Failed ");
                exit(0);
            }
            if( PID == 0 )/*child2*/
            {
                name = "grandchild2";
                printf("\n\n%s \n",name);
                printf("My PID is %d\n",getpid());
                printf("My Parent PID is %d\n",getppid());
            }
        }
    }
    return 0;
}