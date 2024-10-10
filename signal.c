/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  flag = 1;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  
  while (1)
  {
    if (flag)
    {
      printf("Turning was right!\n");
      flag = 0;
      alarm(5);
    }
  }
  return 0;
}