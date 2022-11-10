#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>

int sum;
void *runner (void *param);

int main(int argc, char *argv[]) {
	pid_t pid;
	
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]);
	pthread_join(tid, NULL);

	if (sum % 2 == 0) {
		pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork unsuccessful\n");
		}
		else if (pid == 0) {
			printf("fuck off you proper even cunt (PID = %d)\n", pid);
		}
		else if (pid > 0) {
			wait(NULL);
			printf("pardon my child, sir (PID = %d)\n", pid);
		}
	}

	printf("sum = %d\n", sum);

	return 1;
}

void *runner (void *param) {
	int upper_limit = atoi(param);
	sum = 0;

	for (int i = 1; i <= upper_limit; i++) {
		sum += i;
	}

	pthread_exit(0);
}
