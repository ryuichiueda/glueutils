#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void usage(void){
	fputs("switch12: switch stdout and stderr\n", stderr);
	fputs("usage: switch12 <command> [args]\n", stderr);
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

int main(int argc, char * argv[])
{
	if(argc < 2){
		usage();
		exit(1);
	}

	trydup2(1, 3);
	trydup2(2, 1);
	trydup2(3, 2);

	return - execvp(argv[1], &argv[1]);
}
