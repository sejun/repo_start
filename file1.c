#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 512

void main()
{
	char buffer[BUFSIZE];
	int filedes;
	ssize_t nread;
	long total = 0;

	if((filedes = open("data.txt", O_RDONLY))==-1)
	{
		printf("error in opening anotherfile\n");
		exit(1);
	}

	while((nread=read(filedes, buffer, BUFSIZE))>0)
		total+=nread;

	printf("total chars in anotherfiles: %ld\n", total);
	exit(0);
}
