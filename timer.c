#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile sig_atomic_t flag = 0;
time_t start_time, end_time;

void handle_alarm(int signum)
{
  printf("Hello World!\n");
  flag = 1;
}

void handle_sigint(int signum)
{
  time(&end_time);
  double elapsed = difftime(end_time, start_time);
  printf("Program ran for %.f seconds. \n", elapsed);
  exit(0);
}

int main (int argc, char *argv[])
{
  time(&start_time);
  signal(SIGALRM, handle_alarm);
  signal(SIGALRM, handle_sigint);

  alarm(1);

  while (1)
  {
    if (flag)
    {
      flag = 0;
      alarm(1);
    }
  }
  return 0;
}