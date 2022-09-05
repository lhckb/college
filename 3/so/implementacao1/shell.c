#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int main(void)
{
    char *args[MAX_LINE/2 + 1];	/* command line has max of 40 arguments */
    int should_run = 1;		/* flag to help exit program*/
	
    while (should_run) {

		printf("lhcc seq> ");
			fflush(stdout);

		fgets(args, MAX_LINE, stdin);
		/*
		After read the input, the next steps are:
			- create n child process with fork() command
			- the child process will invoke execvp()
			- parent will invoke wait() unless command line include &	 
		*/
		
		if (strcmp("exit\n", args) == 0) {
			should_run = 0;
		}
    }
	return 0;
}
