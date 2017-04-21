//
// Created by arnito on 21/04/17.
//

#include "Beat.h"

Beat::Beat(const sf::Time& timespamp, const InputFlags& flags) {
    //TODO
}
Beat::~Beat(){

}

sf::Time Beat::getTimestamp() const{
    return mTimestamp;
}
InputFlags Beat::getInputFlags() const{
    return mFlags;
}



BeatState Beat::getCurrentState() const{
    return mState;
}


void Beat::update(const sf::Time& current_time, InputFlags& flags){
    //TODO
}

Inputs::Key Beat::getKey() const{
    //TODO
}