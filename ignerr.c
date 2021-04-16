#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void usage(void){
	fputs("ignerr: ignore exit status\n", stderr);
	fputs("usage: ignerr <command> [args]\n", stderr);
	fputs("\nCopyright (C) 2021 Ryuichi Ueda\n", stderr);
	fputs("Released under the MIT License.\n", stderr);
	fputs("https://github.com/ryuichiueda/glueutils\n", stderr);
}

int main(int argc, char * argv[])
{
	if(argc < 2){
		usage();
		exit(1);
	}

	int pid = fork();
	if(pid == 0)//child 
		return -execvp(argv[1], &argv[1]);

	waitpid(pid, NULL, 0);
	return 0;
}
