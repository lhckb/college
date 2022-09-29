#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
	int bursts[] = {5, 7, 2};
	int bursts_copy[] = {5, 7, 2};
	int inits[] = {0, 2, 5};
	int nop = 3;
	int count = nop;
	int q = 2;
	int time = 0;
	int i = 0;
	int aux;
	
	printf("\nProcess \t Burst time \t Turnaround time\n");

	while (count != 0) {
		if (inits[i] <= time && bursts_copy[i] > 0) {
			if (bursts_copy[i] <= q) {
				time += bursts_copy[i];
				count--;
				bursts_copy[i] = 0;

				printf("Process #%d \t %d \t %d\n", i, bursts[i], time-inits[i]);
			}
		}
		else {
			time += q;
			bursts_copy[i] -= q;
		}
	}
	
	i = (i + 1) % nop;
	

	return 0;
}
