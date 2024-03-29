#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_cond_t cond1;
pthread_cond_t cond2;
pthread_t tida;
pthread_t tidb;
pthread_t tidc;
void *A(void *arg) {
    
    cout << "A" << endl;
    pthread_mutex_unlock(&mutex1);
}
void *B(void *arg) {
    pthread_mutex_lock(&mutex1);
     
    cout << "B" << endl;
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
}
void *C(void *arg) {
    pthread_mutex_lock(&mutex2);
    cout << "C" << endl;
    pthread_mutex_unlock(&mutex2);
}

int main()
{
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    pthread_mutex_lock(&mutex1);
    pthread_mutex_lock(&mutex2);

    pthread_create(&tida, NULL, A, NULL);
    pthread_create(&tidb, NULL, B, NULL);
    pthread_create(&tidc, NULL, C, NULL);
    pthread_join(tida, NULL);
    pthread_join(tidb, NULL);
    pthread_join(tidc, NULL);
    return 0;
}

