#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/prctl.h>

void usage(void){
	fputs("rep: repeatedly excute the same command\n", stderr);
	fputs("usage: rep <num> <command> [args]\n", stderr);
	fputs("\nCopyright (C) 2021 Ryuichi Ueda\n", stderr);
	fputs("Released under the MIT License.\n", stderr);
	fputs("https://github.com/ryuichiueda/glueutils\n", stderr);
}

/*
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
*/

int main(int argc, char * argv[])
{
	if(argc < 3){
		usage();
		exit(1);
	}

	long rep = strtol(argv[1], NULL, 10);
	if(errno != 0){
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(1);
	}

	int lasterror = 0;
	for(int i=0;i<rep;i++){
		int pid = fork();
		if(pid == 0){//child proc
			return -execvp(argv[2], &argv[2]);
		}

		int wstatus;
		int wpid;
		if((wpid = waitpid(pid, &wstatus, 0)) > 0){
			if(WIFEXITED(wstatus) && WEXITSTATUS(wstatus)){
				lasterror = WEXITSTATUS(wstatus);
			}
		}else{
			fprintf(stderr, "Error: waiting child error");
			exit(1);
		}
	}
	exit(lasterror);
}
