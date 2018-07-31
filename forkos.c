#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
int main()
{
	pid_t pid;
	pid = fork();
	if ( pid < 0)
	{
		printf("Fork Failure");
	}
	else if( 0 == pid)
	{
		printf("Child\t");
		printf("%d\n",getpid());	
                printf("%d\n",getpriority(PRIO_PROCESS,getpid()));
 for(;;)
        {
}

		
}
	else
	{
		printf("Parent\t");
                printf("%d",getppid());

	}
	return 0;
}
