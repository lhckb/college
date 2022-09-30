#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int style = 0;

void splitInputIntoArgs(char *input, char *args[]) {
	// put input into a buffer, then copy buffer into args[arg_count]

	char *buffer;
	int arg_count = 0, arg_index = 0, input_index = 0, true = 1;

	// while (true) {
	// 	if (input[input_index] == ';') {
	// 		strcpy(args[arg_count], buffer);
	// 		buffer = NULL;
	// 		arg_index = 0;
	// 		arg_count++;
	// 	}
	// 	else {
	// 		buffer[arg_index] = input[input_index];
	// 	}

	// 	input_index++;
	// }

	// while (true) {
	// 	if (input[input_index] == ';') {
	// 		arg_count++;
	// 		arg_index = 0;
	// 		// input_index++;
	// 	}
	// 	else if (input[input_index] == '\n') {
	// 		// input_index++;
	// 	}
	// 	else {
	// 		args[arg_count][arg_index] = input[input_index];
	// 		arg_index++;
	// 		// input_index++;
	// 	}
	// 	if (input[input_index] == '\0') {
	// 		true = 0;
	// 	}
	// 	input_index++;
	// }
}

int main(void)
{
	char *args[MAX_LINE/2 + 1];	/* command line has max of 40 arguments, list of pointers to char */
	char *input;
	int should_run = 1;		/* flag to help exit program*/

	while (should_run) {

		if (style == 0) printf("lhcc seq> ");
		if (style == 1) printf("lhcc par> ");
		fflush(stdout);

		fgets(input, MAX_LINE * 40, stdin);

		if (!strcmp(input, "exit\n")) should_run = 0;
		else {
			splitInputIntoArgs(input, args);
		}

		/*
		After read the input, the next steps are:
		- create n child process with fork() command
		- the child process will invoke execvp()
		- parent will invoke wait() unless command line include &	 
		*/
	}
	return 0;
}