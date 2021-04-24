#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <mutex>

class singleTon{
    public:
        static singleTon *getInstance() {
            if (instance == nullptr) {
                std::unique_lock<std::mutex> lock(m_mutex);
                std::cout << "I have get the lock!" << std::endl;
                if (instance == nullptr) {
                    std::cout << "I'm into the room" << std::endl;
                    instance = new singleTon();
                }
            }
            return nullptr;
        }

        void say() {
            std::cout << "666" << std::endl;
        }

    private:
        singleTon() {}
        ~singleTon() {}
        singleTon *operator=(const singleTon &A);
        singleTon(const singleTon &A);
        static std::mutex m_mutex;
        static singleTon *instance;
};

singleTon *singleTon::instance = nullptr;
std::mutex singleTon::m_mutex;


void *A(void *arg){
    singleTon *a = (singleTon *)arg;
    a = singleTon::getInstance();
    std::cout << "a address : " << &a << std::endl;
    a->say();
    pthread_exit(0);
    return nullptr;
}

void *B(void *arg){
    singleTon *a = singleTon::getInstance();
    a->say();
    pthread_exit(0);
    return nullptr;
}

int main()
{
    pthread_t tida;
    pthread_t tidb;
    singleTon *a;
    pthread_create(&tida, NULL, B, (void *)a);
    pthread_create(&tidb, NULL, B, a);
    pthread_join(tida, NULL); 
    pthread_join(tidb, NULL); 
    return 0;
}

