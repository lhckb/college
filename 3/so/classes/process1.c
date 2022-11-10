#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

  pid_t pid = getpid();
  printf("PID = %i \n", pid);  // prints process PID on start

  pid_t pid2 = fork();  // parent process gets child PID, and child PID gets 0
  // printf("PID = %i \n", pid2);

  pid = getpid();
  wait(NULL);
  printf("PID = %i \n", pid);  // prints process PID on start

  printf("\n\n\n");

  if (pid2 < 0) { 
    fprintf(stderr, "Fork failed\n");
  }
  if (pid2 == 0) {
    printf("Child process, PID = %d\n", pid2);
  }
  else {
    printf("Parent process, PID = %d\n", pid2);
  }

  return 1;
}