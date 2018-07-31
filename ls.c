#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
int main()
{
	char dirname[10];
	DIR *p;
	struct dirent *d;
	printf("enter directory name\n");
	gets(dirname);
	p=opendir(dirname);
	if(p==NULL)
	{
		perror("cannot find directory");
		exit(1);	
	}
	while(d=readdir(p))
		printf("%s\n",d->d_name);
	//	printf("%s\n",d->d_type);
	return 0;
}

