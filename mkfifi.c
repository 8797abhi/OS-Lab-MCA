#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int  main()
{
    int file1 = mkfifo( "abc.txt" , 0777 ) ;
   // int file2 = mkfifo( "def.txt" , 0777 ) ;
  
    int status;
    char * buf;
    pid_t  pid = 0;
    pid = fork();
    printf("%d\n",pid);
    if( 0 == pid )//child process
    {
       // printf("Enter the File Name: \n");
       // printf("%d\n",file1);
        status = open("abc.txt" , O_WRONLY);
        printf("Enter the File Name: \n");
       printf("%d\n",status);
        write(status,"hello!",strlen("hello!"));

        //printf("Enter the File Name:");
       
    //    // gets(buf);
    //     write(file1 , &buf, strlen(buf));
        

    }
    else //parent process
    {
       status = open("abc.txt" , O_RDONLY);
       /* int no = read(status,&buf,80);
        printf("%s",buf);
        //wait(NULL);
        //sleep(15);*/
    }
}