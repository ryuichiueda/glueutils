#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void usage(void){
	fputs("errlog: logging stderr to a file\n", stderr);
	fputs("usage: errlog <filename> <command> [args]\n", stderr);
	fputs("\nCopyright (C) 2021 Ryuichi Ueda\n", stderr);
	fputs("Released under the MIT License.\n", stderr);
	fputs("https://github.com/ryuichiueda/glueutils\n", stderr);
}

int main(int argc, char * argv[])
{
	if(argc < 3){
		usage();
		exit(1);
	}

	dup2(1, 3);
	dup2(2, 1);
	dup2(3, 2);

	return - execvp(argv[1], &argv[1]);
}
