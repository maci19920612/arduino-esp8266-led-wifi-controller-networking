#include "executors/ExecutorContainer.h"

#include "executors/SerialExecutor.h"
#include "executors/WifiAPExecutor.h"
#include "executors/WifiExecutor.h"
#include "utils/list.h"
#include <Arduino.h>

ExecutorContainer* ExecutorContainer::instance = 0;
ExecutorContainerEntry* createEntry(Executor executorKey, BaseExecutor* executor);

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
        createEntry(Executor::serial, new SerialExecutor())
    );
    
    this->executors.add(
        createEntry(Executor::wifi, new WifiExecutor())
    );

    this->executors.add(
        createEntry(Executor::wifiAP, new WifiAPExecutor())
    );
    
    this->enable(Executor::serial);
};

//Helper functions
ExecutorContainerEntry* createEntry(Executor executorKey, BaseExecutor* executor){
    ExecutorContainerEntry* ret = new ExecutorContainerEntry();
    ret->state = false;
    ret->executorKey = executorKey;
    ret->executor = executor;
    return ret;
};