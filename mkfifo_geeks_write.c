// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd;

	// FIFO file path
	char * myfifo = "/tmp/myfifo";

	// Creating the named file(FIFO)
	// mkfifo(<pathname>, <permission>)
	mkfifo(myfifo, 0666);

	char arr1[80], arr2[80];
		// Open FIFO for write only
		fd = open(myfifo, O_WRONLY);

		// Take an input arr2ing from user.
		// 80 is maximum length
		fgets(arr2, 80, stdin);
		
		//scanf("%s",arr2);

		/* size_t ln = strlen(arr2) - 1;
		if (*arr2 && arr2[ln] == '\n') 
    		arr2[ln] = '\0';
 */

		//printf("%s",arr2);

		// Write the input arr2ing on FIFO
		// and close it
		write(fd, arr2, strlen(arr2)+1);
		close(fd);

		// Open FIFO for Read only
		fd = open(myfifo, O_RDONLY);

		// Read from FIFO
			printf("User2:\n");
		while(read(fd, &arr1,1) > 0)
		{
			
			//printf("%c",arr1);
			write(STDOUT_FILENO,&arr1,1);
		
		}
		// Print the read message
	
		close(fd);
	
	return 0;
}
