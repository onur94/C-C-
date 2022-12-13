#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;
  
pthread_t pthread1, pthread2;
pthread_barrier_t   barrier;
  
void *thread_function(void *arg)
{
    char id = *(char *)arg;
 
    cout << "Task-" << id << " has started" << endl;
    if (id == '1')
        sleep(2);
    else
        sleep(4);

    cout << "Task-" << id << " waiting at barrier" << endl;
    pthread_barrier_wait(&barrier); // At this point, the two tasks will await each other.
    sleep(1);
    
    cout << "Task-" << id << " has finished" << endl;

    return NULL;
}
  
int main(void)
{
    pthread_barrier_init (&barrier, NULL, 2);

    pthread_create(&pthread1, NULL, thread_function, (void *)"1");
    pthread_create(&pthread2, NULL, thread_function, (void *)"2");

    pthread_join(pthread1, NULL);
    pthread_join(pthread2, NULL);
  
    return 0;
}