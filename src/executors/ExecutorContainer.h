#ifndef __EXECUTOR_CONTAINER
#define __EXECUTOR_CONTAINER
//Libs
#include <Arduino.h>
#include "utils/list.h"
//Executors
#include "executors/BaseExecutor.h"
#include "executors/SerialExecutor.h"
#include "executors/WifiAPExecutor.h"
#include "executors/WifiExecutor.h"


enum Executor{
    serial,
    wifi,
    wifiAP
};

struct ExecutorContainerEntry{
    Executor executorKey;
    bool state;
    BaseExecutor* executor;
};


class ExecutorContainer{
    public:
        static ExecutorContainer* getInstance();
        void execute();
        void enable(Executor executorKey);
        void disable(Executor executorKey);
    private:
        static ExecutorContainer* instance;

        List<ExecutorContainerEntry*> executors;

        ExecutorContainer();
        ExecutorContainerEntry* createEntry(Executor executorKey, BaseExecutor* executor);
};

ExecutorContainer* ExecutorContainer::instance = 0;

//Static functions
ExecutorContainer* ExecutorContainer::getInstance(){
    if(instance == NULL){
        instance = new ExecutorContainer();
    }
    return instance;
};

//Public functions
void ExecutorContainer::execute(){
    for(int i = 0; i < this->executors.size(); i++){
        ExecutorContainerEntry* entry = this->executors[i];
        if(entry->state){
            entry->executor->execute();
        }
    }
};

void ExecutorContainer::enable(Executor executorKey){
    for(int i = 0; i < this->executors.size(); i++){
        ExecutorContainerEntry* entry = this->executors[i];
        if(entry->executorKey == executorKey){
            if(!entry->state){
                entry->state = true;
                entry->executor->init();
            }
            return;
        }
    }
    error("Enable: Not found executor    with following key: %d", executorKey);
};

void ExecutorContainer::disable(Executor executorKey){
    for(int i = 0; i < this->executors.size(); i++){
        ExecutorContainerEntry* entry = this->executors[i];
        if(entry->executorKey == executorKey){
            if(entry->state){
                entry->state = false;
                entry->executor->dispose();
            }
            return;
        }
    }
    error("Disable: Not found executor with following key: %d", executorKey);
};

//Private functions
ExecutorContainer::ExecutorContainer(){
    this->executors.add(
        this->createEntry(Executor::serial, new SerialExecutor())
    );
    
    this->executors.add(
        this->createEntry(Executor::wifi, new WifiExecutor())
    );

    this->executors.add(
        this->createEntry(Executor::wifiAP, new WifiAPExecutor())
    );
    
    this->enable(Executor::serial);
};

ExecutorContainerEntry* ExecutorContainer::createEntry(Executor executorKey, BaseExecutor* executor){
    ExecutorContainerEntry* ret = new ExecutorContainerEntry();
    ret->state = false;
    ret->executorKey = executorKey;
    ret->executor = executor;
    return ret;
};

#endif