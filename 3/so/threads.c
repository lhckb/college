#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

double avg;
int max_val;
int min_val;

struct param_t {
	int size;
	int *values;
};
typedef struct param_t param_t;

void *average (void *);
void *getMax (void *);
void *getMin (void *);

int main (int argc, char* argv[]) {
	if (argc <= 1) {
		printf("No arguments passed.");
		exit(0);		
	}	

	int args_copy[argc-1];
	
	for (int i = 0; i < argc-1; i++) {
		args_copy[i] = atoi(argv[i+1]);
	}

	param_t params = {argc - 1, args_copy};

	pthread_t thread1, thread2, thread3;
	if (pthread_create(&thread1, NULL, (void*) average, (void*) &params)) {
		fprintf(stderr, "Thread creation failed.");
		exit(EXIT_FAILURE);
	}
	if (pthread_create(&thread2, NULL, (void*) getMax, (void*) &params)) {
		fprintf(stderr, "Thread creation failed.");
		exit(EXIT_FAILURE);
	}
	if (pthread_create(&thread3, NULL, (void *) getMin, (void *) &params)) {
		fprintf(stderr, "Thread creation failed.");
		exit(EXIT_FAILURE);
	}
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("AVG = %.2lf\n", avg);
	printf("MAX = %d\n", max_val);
	printf("MIN = %d\n", min_val);

	exit(EXIT_SUCCESS);
}

void *average (void *param) {
	avg = 0;
	param_t *params;
	params = (param_t *) param;

	int sz = params->size;

	for (int c = 0; c < sz; c++) {
		avg += params->values[c];
	}
	
	avg = avg / (double) sz;
}

void *getMax(void *param) {
	param_t *params = (param_t *) param;
	max_val = params->values[0];
	for (int c = 1; c < params->size; c++) {
		if (params->values[c] > max_val) {
			max_val = params->values[c];
		} 
	}	
}

void *getMin (void *param) {
	param_t *params = (param_t *) param;
	min_val = params->values[0];
	for (int c = 1; c < params->size; c++) {
		if (params->values[c] < min_val) {
			min_val = params->values[c];
		}
	}
}
