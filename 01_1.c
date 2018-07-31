#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t child_a, child_b,gchild_a, gchild_b;
    char * name = NULL;
    child_a = fork();

    if (child_a == 0) {
    name = "child1";
        printf("\n\n%s \n",name);
        printf("My PID is %d\n",getpid());
        printf("My Parent PID is %d\n",getppid());
        gchild_a = fork();
        if(gchild_a == 0)
        {
            name = "grand child1";
        printf("\n\n%s \n",name);
        printf("My PID is %d\n",getpid());
        printf("My Parent PID is %d\n",getppid());
        }
} else {
    child_b = fork();

    if (child_b == 0) {
        name = "child2";
        printf("\n\n%s \n",name);
        printf("My child 2PID is %d\n",getpid());
        printf("My Parent PID is %d\n",getppid());
          gchild_b = fork();
        if(gchild_b == 0)
        {
            name = "grand child2";
        printf("\n\n%s \n",name);
        printf("My PID is %d\n",getpid());
        printf("My Parent PID is %d\n",getppid());
        }
    } else {
        name = "Parent";
        printf("\n\n%s \n",name);
        printf("My PID is %d\n",getpid());
        printf("My Parent PID is %d\n",getppid());
    }
}
    
}