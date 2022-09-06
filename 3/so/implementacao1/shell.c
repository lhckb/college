#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int main(void)
{
	char *args[MAX_LINE/2 + 1];	/* command line has max of 40 arguments */
	char command[MAX_LINE/2 + 1];
	int should_run = 1;		/* flag to help exit program*/
	int style = 0;

	while (should_run) {

		if (style == 0) printf("lhcc seq> ");
		if (style == 1) printf("lhcc par> ");
			fflush(stdout);

		fgets(args, MAX_LINE, stdin);

		int true = 1, count = 0;
		while (true) {
			if (args[count] == '\n') true = 0;

			else {
				if (args[count] != ';' && args[count] != '\n') {
					printf("debug\n");
					command[count] = args[count];
					count ++;
				}
				else {
					system(command);
				}
			}
		}

		/*
		After read the input, the next steps are:
			- create n child process with fork() command
			- the child process will invoke execvp()
			- parent will invoke wait() unless command line include &
		*/

		// system(args);

		if (strcmp("exit\n", args) == 0) {
			should_run = 0;
    }

	}
	return 0;
}
