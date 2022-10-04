#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int style = 0;

void splitInputIntoComms(char *input, char *comms[MAX_LINE / 2 + 1]) {
	int comm_count = 0, true = 1;
  char *piece;

  while (true) {
    piece = strtok_r(input, ";", &input);
    if (piece != NULL) {
      comms[comm_count] = piece;
      comm_count++;
    }
    else {
      true = 0;
    }
  }
}

void splitCommandIntoArgs(char *command, char *res[MAX_LINE / 2 + 1]) {
  int true = 1, arg_count = 0;
  char *piece;

  while (true) {
    piece = strtok_r(command, " ", &command);
    if (piece != NULL) {
      res[arg_count] = piece;
      arg_count++;
    }
    else {
      true = 0;
    }
  }
}

void executeSequential(char *command[]) {
  printf("%s\n", command);
  char *args[MAX_LINE / 2 + 1];
  splitCommandIntoArgs(command, args);
  printf("%s\n", args[0]);
}

int main(void)
{
	char *comms[MAX_LINE/2 + 1];	/* command line has max of 40 arguments, list of pointers to char */
	char input[MAX_LINE];

	int should_run = 1;	

	while (should_run) {

		if (style == 0) printf("lhcc seq> ");
		if (style == 1) printf("lhcc par> ");
		fflush(stdout);

		fgets(input, MAX_LINE, stdin);
		printf("%s\n\n", input);

		if (!strcmp(input, "exit\n")) should_run = 0;
		else {
      splitInputIntoComms(input, comms);

      if (style == 0) executeSequential(comms);
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