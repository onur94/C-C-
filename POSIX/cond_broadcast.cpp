#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>
using namespace std;

pthread_cond_t cond  = PTHREAD_COND_INITIALIZER;
pthread_cond_t result_cond  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex[4] = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER};
pthread_mutex_t result_mutex = PTHREAD_MUTEX_INITIALIZER;

int arr[100000];
int flag = 0;

struct timeval diff, start, finish;

void *result_callback( void *arg )
{
	pthread_mutex_lock(&result_mutex);
	while(flag != 6)
		pthread_cond_wait(&result_cond, &result_mutex);
	gettimeofday(&finish, NULL);
	diff.tv_sec = finish.tv_sec - start.tv_sec;
	diff.tv_usec = finish.tv_usec - start.tv_usec;
	cout << "Time taken: " << diff.tv_sec*1000000 + diff.tv_usec << "us" << endl;
	pthread_mutex_unlock(&result_mutex);
	return NULL;
}

void *thread_callback( void *arg )
{
     int num = *(char *)arg - '0';

     pthread_mutex_lock(&mutex[num]);
     cout << "Thread-" << num << " waiting condition" << endl;
     pthread_cond_wait(&cond, &mutex[num]);
     cout << "Thread-" << num << " running" << endl;
     for (int i = 0; i < 100000; ++i) {
		arr[i] = pow(2, i) + pow(2, i);
	 }
     pthread_mutex_unlock(&mutex[num]);
     flag += num;
     pthread_cond_signal(&result_cond);
     cout << "Thread-" << num << " stopped" << endl;
     return NULL;
}

int main()
{
     pthread_t thread1, thread2, thread3, thread4, thread5;

     pthread_create( &thread1, NULL, thread_callback, (void*) "0");
     pthread_create( &thread2, NULL, thread_callback, (void*) "1");
     pthread_create( &thread3, NULL, thread_callback, (void*) "2");
     pthread_create( &thread4, NULL, thread_callback, (void*) "3");
     pthread_create( &thread5, NULL, result_callback, NULL);

     sleep(1);
     gettimeofday(&start, NULL);
     pthread_cond_broadcast(&cond);

     pthread_join(thread5, NULL);

     cout << "Main finished" << endl;

     return 0;
}

