#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *myfunc(void *args) {
  int i;
  char *name = (char *)args;
  for (i = 1; i < 50; i++) {
    printf("%s: %d\n", name, i);
  }
  return NULL;
}

int main() {
  pthread_t th1;
  pthread_t th2;

  pthread_create(&th1, NULL, myfunc, "th1");
  pthread_create(&th2, NULL, myfunc, "th2");

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);

  return 0;
}
