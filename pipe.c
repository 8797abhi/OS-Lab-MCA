#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int pipefd1[2];
    int pipefd2[2];
    pid_t cpid;
    char buf;
    int fd = open("try.txt",O_CREAT|O_WRONLY,0744);
    if( fd == -1)
    {
        perror("Open:");
        exit(EXIT_FAILURE); 
    }
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefd2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(cpid == 0) // child process
    {
      //write(1,"childs!!",9);
        close(pipefd1[0]); //close read end of the first pipe
        //write(1,"child!!",8);
        close(pipefd2[1]); //close write end of the second pipe
        //write(1,"child!!",8);
        write(pipefd1[1],argv[1],strlen(argv[1]));
        //write(1,"child!!",8);
        close(pipefd1[1]); //close write end of the first pipe
        //write(1,"child!!",8);
        //write(1,"child atka upar!!",18);
        while ( read(pipefd2[0] , &buf , 1 ) > 0 )
        {
            //write(1,"child atka!!",13);
            write(fd,&buf,1);
            write(1,"child atka!!",13);
        }
        write(1,"child atka!!",13);
        close(pipefd2[0]);  //close read end of the second pipe
        //write(1,"child!!",8);
        _exit(EXIT_SUCCESS);
        //write(1,"child!!",8);

    }
    else // parent process
    {
        write(1,"parents!!",10);
        close(pipefd1[1]); //close write end of the first pipe
//        write(1,"parent atka!!",14);
        close(pipefd2[0]); //close read end of the second pipe
  //      write(1,"parent!!",9);
    write(1,"parent atka upar!!",19);
        while ( read(pipefd1[0] , &buf , 1 ) > 0 )
        {
   //         write(1,"parent atka!!",14);
            write(fd,&buf,1);
     //      write(1,"parent atka!!",14);
        }
        write(1,"parent atka!!",14);
        close(pipefd1[0]);
        //write(1,"parent!!",9);
        
        //write(1,"parent!!",9);
        write(pipefd2[1],argv[1],strlen(argv[1]));
        //write(1,"parent!!",9);
        
        close(pipefd2[1]);
        wait(NULL);
        //write(1,"parent!!",9);
        exit(EXIT_SUCCESS);
    }
}