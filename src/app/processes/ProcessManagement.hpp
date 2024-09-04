#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <memory>
#include <mutex>
#include <atomic>
#include <semaphore.h>

class ProcessManagement
{
    sem_t* itemsSemaphore; // semaphore to signal that there are items in the queue
    sem_t* emptySlotsSemaphore; // semaphore to signal that there are empty slots in the queue

public:
    ProcessManagement();
    ~ProcessManagement(); //free share memory
    bool submitToQueue(std::unique_ptr<Task> task);
    void executeTask();

private:
    struct SharedMemory {
        std::atomic<int> size;
        char tasks[1000][256];
        int front;
        int rear;

        void printSharedMemory() {
            std::cout<<size<<std::endl;
            std::cout<<front<<std::endl;
            std::cout<<rear<<std::endl;
        }

    };
    SharedMemory* sharedMem;
    int shmFd;
    const char* SHM_NAME = "/my_queue";
    std::mutex queueLock; // mutex to protect the shared memory
};

#endif