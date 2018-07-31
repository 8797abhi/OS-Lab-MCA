#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>


int main()
{
    int mqid,msgg = -1;
    mqid = ftok(".",'a');
    printf("%d",mqid);
    msgg = msgget(mqid,IPC_CREAT);
    printf("\n%d",msgg);
}