#include "utils/list.h"


template <typename T> List<T>::~List(){
    delete itemContainer;
};

template <typename T> List<T>::List(){
    this->itemContainer = new T[this->INCREASE_STEP];
    this->maxSize = this->INCREASE_STEP;
    this->internalSize = 0;
};

template<typename T> void List<T>::add(T item){
    if(this->internalSize == this->maxSize){
       this->increaseContainerSize();
    }
    this->itemContainer[this->internalSize] = item;
    this->internalSize++;
};

template <typename T> void List<T>::add(int index, T item){
    if(index >= this->internalSize){
        add(item);
        return;
    }
    if(index < 0){
        //Error occured!!!
        return;
    }
    if(this->internalSize == this->maxSize){
        this->increaseContainerSize();
    }
    this->move(index, 1);
    this->itemContainer[index] = item;
};

template <typename T> T List<T>::operator[](int index){
    return this->itemContainer[index];
};

template <typename T> int List<T>::find(T item){
    for(int i = 0; i < this->internalSize; i++){
        if(item == this->itemContainer[i]){
            return i;
        }
    }
    return -1;
};

template <typename T> void List<T>::remove(T item){
    int index = find(item);
    if(index == -1){
        //Item not exists
        return;
    }
    move(index, -1);
    if(this->maxSize - this->INCREASE_STEP <= this->internalSize){
        this->decreaseContainerSize();
    }
};

template <typename T> void List<T>::removeAt(int index){
    if(index < 0 || index >= this->internalSize){
        //Error occured: Index not found!
        return;
    }
    move(index, -1);
    if(this->maxSize - this->INCREASE_STEP <= this->internalSize){
        this->decreaseContainerSize();
    }
};

template <typename T> int List<T>::size(){
    return this->internalSize;
};


template <typename T>void  List<T>::increaseContainerSize(){
    T* currentItems = this->itemContainer;
    this->maxSize += this->INCREASE_STEP;
    this->itemContainer = new T[this->maxSize];
    for(int i = 0; i < this->internalSize; i++){
        this->itemContainer[i] = currentItems[i];
    }
    delete currentItems;
};

template <typename T> void List<T>::decreaseContainerSize(){
    if(this->maxSize - this->INCREASE_STEP < this->internalSize){
        return;
    }
    T* currentItems = this->itemContainer;
    this->maxSize -= this->INCREASE_STEP;
    this->itemContainer = new T[this->maxSize];
    for(int i = 0; i < this->internalSize; i++){
        this->itemContainer[i] = currentItems[i];
    }
    delete currentItems;
};

template <typename T> void List<T>::move(int startIndex, int distance){
    if(this->maxSize < this->internalSize + distance){
        this->increaseContainerSize();
    }

    int step = 1;
    int arrayStartIndex = this->internalSize;
    if(distance < 0){
        step = -1;
        arrayStartIndex = startIndex + 1;
    }
    if(distance < 0){
        for(int i = startIndex + -1 * distance; i < this->internalSize; i++){
            this->itemContainer[i + distance] = this->itemContainer[i];
        }
    }else{
        for(int i = this->internalSize + distance - 1; i > startIndex + distance - 1; i--){
            this->itemContainer[i] = this->itemContainer[i - distance];
        }
    }

    this->internalSize += distance;
}