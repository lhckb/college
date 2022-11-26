#ifndef UTILS_H
#define UTILS_H

#define REALLY_BIG_NUM 1000

typedef struct process_st {
  char name[REALLY_BIG_NUM];
  int period;
  int burst;
  int elapsed_burst;
  char status;
} process_st;

typedef struct log_st {
  char proc_name[REALLY_BIG_NUM];
  char status;
  int units;
} log_st;

void createProcess(char*, process_st*, process_st*);
void getInputFile(FILE *, process_st *, process_st *);
int getProcessCount(FILE *);
void logProcess(process_st, log_st *, int);
void printLogs(log_st *, process_st *, process_st *, int);
void swapProcesses(process_st *, int);
void sortProcessesByPriority(process_st *);
void printList(process_st *);
int checkInstanceOfSame(process_st, process_st *, log_st *);
int checkAndInsert(process_st *, process_st *, process_st *, int, int, log_st *);
void printList(process_st *);

#endif