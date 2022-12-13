#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  
pthread_t pthread1, pthread2;
pthread_mutex_t lock;
  
void *thread_function(void *arg)
{
    char id = *(char *)arg;
    pthread_mutex_lock(&lock);
  
    printf("Job %c has started\n", id);
  
    sleep(2);
  
    printf("Job %c has finished\n", id);
  
    pthread_mutex_unlock(&lock);
  
    return NULL;
}
  
int main(void)
{
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }
  
    pthread_create(&pthread1, NULL, thread_function, (void *)"1");
    pthread_create(&pthread2, NULL, thread_function, (void *)"2");

    pthread_join(pthread1, NULL);
    pthread_join(pthread2, NULL);
    pthread_mutex_destroy(&lock);
  
    return 0;
}