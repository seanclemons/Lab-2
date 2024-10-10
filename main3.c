#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void childProcess(int childNum) { 
  srandom(time(NULL) + getpid());

  int iterations = random() % 30 + 1;
  
  // Declare loop variable outside for C89 compatibility
  int i;
  for (i = 0; i < iterations ; i++) {
    printf("Child %d Pid: %d is going to sleep!\n", childNum, getpid());
    int sleepTime = random() % 10 + 1;
    sleep(sleepTime);
    printf("Child %d Pid: %d is awake!\nWhere is my Parent: %d ?\n", childNum, getpid(), getppid());
  }
  exit(0);
}

int main() {
  pid_t pid1 = fork();
  if (pid1 < 0) {
    perror("Fork failed for the first child process");
    exit(1);
  } else if (pid1 == 0) {
    childProcess(1);
  }

  pid_t pid2 = fork();
  if (pid2 < 0) {
    perror("Fork failed for the second child process");
    exit(1);
  } else if (pid2 == 0) {
    childProcess(2);
  }

  // Declare status variable
  int status;
  pid_t terminatedChild;

  while ((terminatedChild = wait(&status)) > 0) {
    if (WIFEXITED(status)) {
      printf("Child Pid: %d has completed with exit status: %d\n", terminatedChild, WEXITSTATUS(status));
    } else {
      printf("Child Pid: %d terminated abnormally\n", terminatedChild);
    }
  }

  printf("All child processes have completed\n");
  return 0;
}
