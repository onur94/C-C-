#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

using namespace std;

pthread_t pthread1, pthread2, pthread3;
pthread_cond_t cond  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex[4] = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER};

int arr[100000];

void *thread_function( void *arg )
{
     int num = *(char *)arg - '0';

     pthread_mutex_lock(&mutex[num]);
     cout << "Task-" << num << " waiting condition" << endl;
     pthread_cond_wait(&cond, &mutex[num]);

     cout << "Task-" << num << " running" << endl;
     for (int i = 0; i < 100000; ++i) {
		arr[i] = pow(2, i) + pow(2, i);
	}

     pthread_mutex_unlock(&mutex[num]);
     cout << "Task-" << num << " stopped" << endl;
     
     return NULL;
}

int main()
{
     pthread_create( &pthread1, NULL, thread_function, (void*) "0");
     pthread_create( &pthread2, NULL, thread_function, (void*) "1");
     pthread_create( &pthread3, NULL, thread_function, (void*) "2");

     sleep(2);
     pthread_cond_broadcast(&cond);

     pthread_join(pthread1, NULL);
     pthread_join(pthread2, NULL);
     pthread_join(pthread3, NULL);

     return 0;
}

