#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int arr[5000];
int s;

typedef struct {
  int first;
  int last;
} MY_ARGS;

void *myfunc(void *args) {
  int i;
  MY_ARGS *my_args = (MY_ARGS *)args;
  int first = my_args->first;
  int last = my_args->last;

  for (i = first; i < last; i++) {
    s = s + arr[i];
  }
  return NULL;
}

int main() {

  int i;
  for (i = 0; i < 5000; i++) {
    arr[i] = rand() % 50;
  }

  pthread_t th1;
  pthread_t th2;

  MY_ARGS my_args1 = {0, 2500};
  MY_ARGS my_args2 = {2500, 5000};

  pthread_create(&th1, NULL, myfunc, &my_args1);
  pthread_create(&th2, NULL, myfunc, &my_args2);

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);

  printf("s = %d\n", s);

  return 0;
}
