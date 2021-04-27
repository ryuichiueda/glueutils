#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/prctl.h>

void usage(void){
	fputs("con12: output stderr to stdout with buffering\n", stderr);
	fputs("usage: con12 <command> [args]\n", stderr);
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

void thread_read(void *arg)
{
	int *fd = (int *)arg;
	char buf[1024];
	int ret = 1;
	while (ret > 0){
		int ret = read(*fd, &buf, 1024);
		for(int i=0;i<ret;i++){
			putchar(buf[i]);
		}
	}
	fflush(stdout);

	if(ret == -1){
		fputs("Error: reading error\n", stderr);
		exit(1);
	}
	try_close(*fd);
}

int main(int argc, char * argv[])
{
	if(argc < 2){
		usage();
		exit(1);
	}

	int pips[2];
	if(pipe(pips) < 0){
		fputs("Error: pipe open error", stderr);
			exit(1);
	}

	int epips[2];
	if(pipe(epips) < 0){
		fputs("Error: pipe open error", stderr);
			exit(1);
	}

	int pid = fork();
	if(pid != 0){//parent proc
		try_close(0);
		try_close(pips[1]);
		if(dup2(pips[0], 0) == -1){
			fprintf(stderr, "Error: %s\n", strerror(errno));
			exit(1);
		}
		try_close(pips[0]);
	}else{//child proc
		close(2);
		dup2(epips[1], 2);
		close(epips[1]);

		try_close(pips[1]);

		/*
		close(1);
		dup2(pips[1], 1);
		close(pips[1]);
		*/
		return -execvp(argv[1], &argv[1]);
	}

	pthread_t pthread;
	pthread_create(&pthread, NULL, (void *)thread_read, &epips[0]);

	int wstatus;
	int wpid;
	int lasterror = 0;
	if((wpid = waitpid(pid, &wstatus, 0)) > 0){
		if(WIFEXITED(wstatus) && WEXITSTATUS(wstatus)){
			lasterror = WEXITSTATUS(wstatus);
		}
	}

	exit(lasterror);
}
