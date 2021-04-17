#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void usage(void){
	fputs("ign2: erase stderr\n", stderr);
	fputs("usage: ign2 <command> [args]\n", stderr);
	fputs("\nCopyright (C) 2021 Ryuichi Ueda\n", stderr);
	fputs("Released under the MIT License.\n", stderr);
	fputs("https://github.com/ryuichiueda/glueutils\n", stderr);
}

void trydup2(int oldfd,int newfd)
{
	if(dup2(oldfd, newfd) == -1 || close(oldfd) == -1){
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}
}

int tryopen(char *filename){
	int fd = open(filename, O_WRONLY);
	if(fd < 0){
		printf("Error: %s: %s\n", filename, strerror(errno));
		exit(1);
	}

	return fd;
}

int main(int argc, char * argv[])
{
	if(argc < 2){
		usage();
		exit(1);
	}

	int fd = tryopen("/dev/null");
	trydup2(2, fd);

	return - execvp(argv[1], &argv[1]);
}
