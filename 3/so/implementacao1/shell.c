#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

void clearCommand(char *command);

int main(void)
{
	char args[MAX_LINE/2 + 1];	/* command line has max of 40 arguments */
	char command[MAX_LINE/2 + 1];
	int should_run = 1;		/* flag to help exit program*/
	int style = 0;
	pid_t pid;

	while (should_run) {
		clearCommand(command);

		if (style == 0) printf("lhcc seq> ");
		if (style == 1) printf("lhcc par> ");
			fflush(stdout);

		fgets(args, MAX_LINE, stdin);
		if (strcmp("exit\n", args) == 0) {
			should_run = 0;
			return 0;
		}
		pid = fork();
		if (pid < 0) fprintf(stderr, "Fork failed.\n");
		else if (pid > 0) wait(NULL);
		else {
			int true = 1, count = 0;
			while (true) {
				if (args[count] == ';') {
					true = 0;
				}
				else {
					if (args[count] != '\n') {
						command[count] = args[count];
					}
					else {
						system(command);
						clearCommand(command);
						true = 0;
					}
				}

				count++;
			}
		}
	}
	
	return 0;
}

void clearCommand(char *command) {
	for (int i = 0; i <= MAX_LINE / 2 + 1; i++) {
		command[i] = 0;
	}
}
