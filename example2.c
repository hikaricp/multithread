#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[5000];
int s1 = 0;
int s2 = 0;

void* myfunc1(void* args) {
	int i;
	for(i = 0; i < 2500; i++) {
		s1 = s1 + arr[i];
	}
	return NULL;
}

void* myfunc2(void* args) {
	int i;
	for(i = 2500; i < 5000; i++) {
		s2 = s2 + arr[i];
	}
	return NULL;
}

int main() {

	int i;
	for(i = 0; i < 5000; i++) {
		arr[i] = rand() % 50;
	}

	/* for(i = 0; i < 5000; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	} */

	pthread_t th1;
	pthread_t th2;


	pthread_create(&th1, NULL, myfunc1, NULL);
	pthread_create(&th2, NULL, myfunc2, NULL);
	
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	printf("s1 = %d\n", s1);
	printf("s2 = %d\n", s2);
	printf("s1 + s2 = %d\n", s1 + s2);

	return 0;
}
