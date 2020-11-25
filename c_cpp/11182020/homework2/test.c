#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
  int a = strtol(argv[1], NULL, 10);
  int b = strtol(argv[2], NULL, 10);

  int id = fork();

  if(id==0)
  {
    // In child process
    printf("In child process, a-b: %d\n", a-b);
  }
  else 
  {
    // In parent process
    printf("In parent process, a+b: %d\n", a+b);
  }

  return 0;
}
