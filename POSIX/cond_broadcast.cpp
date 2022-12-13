#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_t pthread1, pthread2, pthread3;
pthread_cond_t cond  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex[4] = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER};

void *thread_function( void *arg )
{
     int num = *(char *)arg - '0';

     pthread_mutex_lock(&mutex[num]);
     cout << "Task-" << num << " waiting condition" << endl;
     pthread_cond_wait(&cond, &mutex[num]);

     cout << "Task-" << num << " running" << endl;
     sleep(2);

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

