#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void usage(void){
	fputs("log2: write stderr to a file\n", stderr);
	fputs("usage: log2 <filename> <command> [args]\n", stderr);
	fputs("\nCopyright (C) 2021 Ryuichi Ueda\n", stderr);
	fputs("Released under the MIT License.\n", stderr);
	fputs("https://github.com/ryuichiueda/glueutils\n", stderr);
}

void trydup2(int oldfd,int newfd)
{
	if(dup2(oldfd, newfd) == -1){
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}
}

int tryopen(char *filename){
	int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0600);
	if(fd < 0){
		printf("Error: %s: %s\n", filename, strerror(errno));
		exit(1);
	}

	return fd;
}

int main(int argc, char * argv[])
{
	if(argc < 3){
		usage();
		exit(1);
	}

	int fd = tryopen(argv[1]);
	trydup2(fd, 2);

	return - execvp(argv[2], &argv[2]);
}
