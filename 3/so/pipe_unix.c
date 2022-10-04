#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 50

int main(int argc, char *argv[]) {
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];

  if (argc > 1) strcpy(write_msg, argv[1]);
  else exit(1);

	pid_t pid;
	int fd[2];

	if (pipe(fd)) {
		fprintf(stderr, "Pipe failed.\n");
		return 1;
	}

	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed.\n");
		return 1;
	}
	else if (pid == 0) {
		close(fd[WRITE_END]);
		read(fd[READ_END], read_msg, BUFFER_SIZE); 
		close(fd[READ_END]);
		printf("the message is = %s\n", read_msg);
	}
	else {
		close(fd[READ_END]);
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
		close(fd[WRITE_END]);
	}

	return 0;
}
