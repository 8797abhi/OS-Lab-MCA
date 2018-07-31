#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
    int fd = -1;
    fd = open("link try",__O_DIRECTORY);
    printf("%d",fd);
}