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