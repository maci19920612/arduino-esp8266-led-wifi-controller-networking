#include "utils/JsonUtil.h"

AllAttributeExists& AllAttributeExists::operator()(String attribute){
    attributes.add(attribute);
    return *this;
};
bool AllAttributeExists::in(JsonObject& target){
    for(int i = 0; i < this->attributes.size(); i++){
        if(!target.containsKey(this->attributes[i])){
            return false;
        }
    }
    return true;
};


//JsonUtil class implementation
JsonUtil* JsonUtil::instance = 0;

//Static functions
JsonUtil* JsonUtil::getInstance(){
    if(instance == 0){
        instance = new JsonUtil();
    }
    return instance;
}
DynamicJsonBuffer* JsonUtil::getBuffer(){
    return this->jsonBuffer;
}

//Private functions
JsonUtil::JsonUtil(){
    this->jsonBuffer = new DynamicJsonBuffer();
}