//
// Created by arnito on 21/04/17.
//

#include "InputFlags.h"
InputFlags::InputFlags(const std::vector<Inputs::Key> &keys) {
    for(int i = 0; i < keys.size(); i++){
        mFlags[keys[i]] = false;
    }
}
InputFlags::~InputFlags(){

}

std::vector<Inputs::Key> &InputFlags::getTrueFlags(std::vector<Inputs::Key> &trueFlags){
    for (std::map<Inputs::Key, bool>::iterator it=mFlags.begin(); it!=mFlags.end(); ++it)
        if(it->second) trueFlags.push_back(it->first);
}

void InputFlags::setFlagsToFalse(){
    for (std::map<Inputs::Key, bool>::iterator it=mFlags.begin(); it!=mFlags.end(); ++it)
        it->second = false;
}
Inputs::Key InputFlags::compareFlags(const std::vector<Inputs::Key> &flags) const{
    Inputs::Key key = NULL;
    for(int i = 0; i < flags.size(); i++){
        if(mFlags[flags[i]]) key = flags[i];
        else return NULL;
    }
    return key;
}