#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct data
{
  int a;
  int b;
};

void* addNum(void* data)
{
  struct data * local = data;

  int a = local->a;
  int b = local->b;
  
  printf("Adding numbers: %d\n", a+b);
  sleep(1);
}

void* minusNum(void* data)
{
  struct data * local = data;

  int a = local->a;
  int b = local->b;
  
  printf("Minus numbers: %d\n", a-b);
  sleep(1);
}

int main(int argc, char** argv)
{
  int a = strtol(argv[1], NULL, 10);
  int b = strtol(argv[2], NULL, 10);

  struct data *data = malloc(sizeof(int));
  
  data->a = a;
  data->b = b;

  // Create threads
  pthread_t thread1;
  pthread_t thread2;

  pthread_create(&thread1, NULL, addNum, data);
  pthread_create(&thread2, NULL, minusNum, data);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}
