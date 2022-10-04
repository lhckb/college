#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

int style = 0;
int general_count;

void removeNewLine(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == '\n') {
      str[i] = 0;
    }
  }
}

void splitInputIntoComms(char *input, char *comms[MAX_LINE / 2 + 1]) {
	int comm_count = 0, true = 1;
  general_count = 0;
  char *piece;

  while (true) {
    piece = strtok_r(input, ";", &input);
    if (piece != NULL) {
      // printf("%s\n", piece);
      comms[comm_count] = piece;
      comm_count++;
      general_count++;
    }
    else {
      true = 0;
    }
  }
}

void splitCommandIntoArgs(char *command, char *args[MAX_LINE / 2 + 1]) {
  int true = 1, arg_count = 0;
  char *piece;

  while (true) {
    piece = strtok_r(command, " ", &command);
    if (piece != NULL) {
      args[arg_count] = piece;
      arg_count++;
    }
    else {
      true = 0;
    }
  }
}

void executeSequential(char **command) {
  // pid_t pid = fork();

  // if (pid < 0) fprintf(stderr, "Fork failed.\n");
  // if (pid == 0) wait(NULL);
  // else {
  //   // printf("%s\n", command[0]);
  // }
  printf("%s\n", command[0]);
  printf("%s\n", command[1]);
  // printf("%s\n", command[2]);
  if (execvp(command[0], command) == -1) fprintf(stderr, "Execvp failed.\n");
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
		
		if (!strcmp(input, "exit\n")) should_run = 0;
		else {
      splitInputIntoComms(input, comms);

      if (style == 0) {
        char *args[general_count];
        for (int i = 0; i < general_count; i++) {
          removeNewLine(comms[i]);
          splitCommandIntoArgs(comms[i], args);
          executeSequential(args);
        }

      } 
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