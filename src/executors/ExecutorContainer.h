#ifndef __EXECUTOR_CONTAINER
#define __EXECUTOR_CONTAINER

//Libs
#include <Arduino.h>
#include "utils/list.h"

//Executors
#include "executors/BaseExecutor.h"



enum Executor{
    serial,
    wifi,
    wifiAP
};
/*
struct ExecutorContainerEntry{
    Executor executorKey;
    bool state;
    BaseExecutor* executor;
};*/


class ExecutorContainer{
    public:
        static ExecutorContainer* getInstance();
        void execute();
        void enable(Executor executorKey);
        void disable(Executor executorKey);
    private:
        static ExecutorContainer* instance;

        List<int> example;
        //List<ExecutorContainerEntry*> executors;

        //ExecutorContainer();
        
};
#endif