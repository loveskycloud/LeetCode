#pragma once
#include <condition_variable>
#include <queue>
#include <mutex>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <thread>

using std::vector;
using std::cout;
using std::endl;

namespace haizei {

class Task {
public :
    template<typename Func_T, typename ...ARGS>
        Task(Func_T f, ARGS ...args) {
            func = std::bind(f, std::forward<ARGS>(args)...);
        }
    void run() {

        func();

    }

private :
    std::function<void()> func;
};




class thread_pool
{
public:
    thread_pool(int thread_size = 5) : thread_size(thread_size), is_started(false), m_mutex(), m_cond(m_mutex)  {

    }
    void start();
    void stop();
    void thread_loop();
    ~thread_pool() {
        stop();
    }
    

private:
    int thread_size;
    std::vector<std::thread *> Threads;
    bool is_started;
    Task *get_one_task();
    void add_one_task(Task *);
    std::queue<Task *> Tasks;
    std::condition_variable m_cond;
    std::mutex m_mutex;
};


void thread_pool::start() {
    is_started = true;
    for (int i = 0; i < thread_size; i ++)  {
        Threads.push_back(new std::thread(&thread_pool::thread_loop, this));
    }
}

void thread_pool::stop() {
    is_started = false;
    for (int i = 0; i < Threads.size(); i++) {
        Threads[i]->join();
        delete Threads[i];
    }
    Threads.clear();
}

void thread_pool::thread_loop() {
    while (is_started) {
        Task t = get_one_task();
        if (t != nullptr) {
            t.run();
        }
    }
}

Task *thread_pool::get_one_task() {
    std::unique_lock<std::mutex> lock(m_mutex);
    while (Tasks.empty() && is_started) {
        m_cond.wait(lock);
    }
    
    Task * t = nullptr;

    if (!Tasks.empty() && is_started) {
        t = Tasks.front();
        Tasks.pop();
    }
    return t;
}


void pthread_pool::add_one_task(Task *t) {
    std::unique_lock<std::mutex> lock(m_mutex);A

    Tasks.push(t);
    
}


};


