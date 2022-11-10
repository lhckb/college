#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <dispatch/dispatch.h>

#define EATING 0
#define HUNGRY 1
#define THINKING 2

#define N 5

int status[N] = {THINKING};
dispatch_semaphore_t sems[N];
dispatch_semaphore_t mutex;

void putFork(int id) {
  dispatch_semaphore_wait(mutex, DISPATCH_TIME_FOREVER);
  status[id] = THINKING;

  int id_l = (id + 4) % N;

  if ((status[id_l] == HUNGRY) && status[(id_l + 4) % N] != EATING) {
    status[id_l] = EATING;
    dispatch_semaphore_signal(sems[id_l]);
  }

  int id_r = (id + 1) % N;
  if ((status[id_r] == HUNGRY) && (status[(id_r + 1) % N] != EATING)) {
    status[id_r] = EATING;
    dispatch_semaphore_signal(sems[id_r]);
  }

  dispatch_semaphore_signal(mutex);
}

void takeFork(int id) {
  dispatch_semaphore_wait(mutex, DISPATCH_TIME_FOREVER);
  
  if((status[(id + 4) % N] != EATING) && (status[(id + 1) % N] != EATING)) {
    status[id] = EATING;
    dispatch_semaphore_signal(mutex);
  }
  else {
    status[id] = HUNGRY;
    printf("Philosopher %d is HUNGRY\n", id);
    dispatch_semaphore_signal(mutex);
    dispatch_semaphore_wait(sems[id], DISPATCH_TIME_FOREVER);
  }

  printf("Philosopher %d is EATING\n", id);
}

void *phil(void* id) {
  int *i = id;

  while (1) {
    printf("Philosopher %d is THINKING\n", *i);
    sleep(1);
    takeFork(*i);
    sleep(1);
    putFork(*i);
  }

}

int main()
{

  pthread_t threads[N];
  int phil_id[] = {0, 1, 2, 3, 4};

  mutex = dispatch_semaphore_create(1);

  for (int i = 0; i < N; i++)
    sems[i] = dispatch_semaphore_create(0);

  for (int i = 0; i < N; i++)
    pthread_create(&threads[i], NULL, phil, &phil_id[i]);

  for (int i = 0; i < N; i++)
    pthread_join(threads[i], NULL);

  exit(EXIT_SUCCESS);
}