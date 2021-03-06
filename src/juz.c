#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/prctl.h>

void usage(void){
	fputs("juz: repeatedly chain the same command in a pipeline\n", stderr);
	fputs("usage: juz <num> <command> [args]\n", stderr);
	fputs("\nCopyright (C) 2021 Ryuichi Ueda\n", stderr);
	fputs("Released under the MIT License.\n", stderr);
	fputs("https://github.com/ryuichiueda/glueutils\n", stderr);
}

void try_close(int fd){
	if(close(fd) == -1){
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}
}

void dup_and_close(int old, int new)
{
	try_close(new);
	if(dup2(old, new) == -1){
		printf("Error: %s\n", strerror(errno));
		exit(1);
	}
	try_close(old);
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

	for(int i=0;i<rep;i++){
		int pips[2];
		if(pipe(pips) < 0){
			fputs("Error: pipe open error", stderr);
			exit(1);
		}

		int pid = fork();
		if(pid == 0){//child proc
			if(i < rep-1){
				try_close(pips[0]);
				dup_and_close(pips[1], 1);
			}else{
				try_close(pips[1]);
			}
			return -execvp(argv[2], &argv[2]);
		}

		//parent proc
		try_close(pips[1]);
		dup_and_close(pips[0], 0);
	}

	int wstatus;
	int wpid;
	int lasterror = 0;
	while((wpid = waitpid(-1, &wstatus, 0)) > 0){
		if(WIFEXITED(wstatus) && WEXITSTATUS(wstatus)){
			lasterror = WEXITSTATUS(wstatus);
		}
	}
	exit(lasterror);
}
