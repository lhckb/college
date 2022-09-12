#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* 80 chars per line, per command */

void clearCommand(char command[][MAX_LINE/2 + 1]);
void executeSequential(char *command);
void executeParallel(char command[][MAX_LINE / 2 + 1], int num);

int main(void)
{
	char args[MAX_LINE/2 + 1];	/* command line has max of 40 arguments */
  char args_copy[MAX_LINE / 2 + 1];
	char command[MAX_LINE/2 + 1][MAX_LINE/2 + 1];
	int should_run = 1;		/* flag to help exit program*/
	int style = 0;

	while (should_run) {
		clearCommand(command);

		if (style == 0) printf("lhcc seq> ");
		if (style == 1) printf("lhcc par> ");
		fflush(stdout);

		fgets(args, MAX_LINE, stdin);
		if (strcmp("exit\n", args) == 0) {
			should_run = 0;
		}
    else if (strcmp("style parallel\n", args) == 0) {
      style = 1;
    }
    else if (strcmp("style sequential\n", args) == 0) {
      style = 0;
    }
    else {
      if (strcmp("!!\n", args) == 0) {
        for (int i = 0; args_copy[i + 1] != '\n'; i++) {
          args[i] = args_copy[i];
        }
      }
      int true = 1, comm_num = 0, comm_count = 0, arg_count = 0;
      while (true) {
        if (args[arg_count] != ';' && args[arg_count] != '\n') {
          command[comm_num][comm_count] = args[arg_count];
        }
        else {
          comm_count = -1;
          comm_num++;
        }
        
        if (args[arg_count] == '\n') {
          true = 0;
        }
        comm_count++;
        arg_count++;
      }

      if (style == 0) {
        for (int i = 0; i < comm_num; i++) {
          executeSequential(command[i]);
        }
      }
      else {
        executeParallel(command, comm_num);
      }
    }

	}
	
	return 0;
}

void executeSequential(char *command) {
  pid_t pid;

  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork failed.\n");
  } 

  else if (pid > 0) wait(NULL);

  else if (pid == 0) {
    system(command);
    raise(15);
  }
}

void executeParallel(char command[][MAX_LINE / 2 + 1], int num) {
  for (int i = 0; i < num; i++) {
    pid_t pid = fork();

    if (pid < 0) {
      fprintf(stderr, "Fork failed.\n");
    } 

    else if (pid > 0) wait(NULL);

    else if (pid == 0) {
      system(command[i]);
      raise(15);
    }
  }
}

void clearCommand(char command[][MAX_LINE/2 + 1]) {
	for (int i = 0; i <= MAX_LINE / 2 + 1; i++) {
    for (int j = 0; j <= MAX_LINE / 2 + 1; j++) {
		  command[i][j] = 0;
    }
	}
}
