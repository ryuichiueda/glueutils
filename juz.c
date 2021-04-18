#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void usage(void){
	fputs("juz: repeatedly chain the same command in a pipeline\n", stderr);
	fputs("usage: juz <num> <command> [args]\n", stderr);
	fputs("\nCopyright (C) 2021 Ryuichi Ueda\n", stderr);
	fputs("Released under the MIT License.\n", stderr);
	fputs("https://github.com/ryuichiueda/glueutils\n", stderr);
}

void fdclose(int fd){
	if(close(fd) == -1){
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}
}


int main(int argc, char * argv[])
{
	if(argc < 3){
		usage();
		exit(1);
	}

	long rep = strtol(argv[1], NULL, 10);
	if(errno != 0){
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}

	for(int i=0;i<rep-1;i++){
		int pips[2];
		if(pipe(pips) < 0){
			fputs("Error: pipe open error", stderr);
			exit(1);
		}

		int pid = fork();
		if(pid != 0){//parent proc
			fdclose(0);
			fdclose(pips[1]);
			dup2(pips[0], 0);
			fdclose(pips[0]);
		}else{//child proc
			fdclose(1);
			fdclose(pips[0]);
			dup2(pips[1], 1);
			fdclose(pips[1]);
			return -execvp(argv[2], &argv[2]);
		}
	}

	return -execvp(argv[2], &argv[2]);
}
