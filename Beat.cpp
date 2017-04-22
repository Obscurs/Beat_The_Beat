//
// Created by arnito on 21/04/17.
//

#include "Beat.h"

Beat::Beat(sf::Time& timespamp, InputFlags& flags):
    mTimestamp(timespamp),
    mFlags(flags) {
    mKey = NULL;
    mState = INACTIVE;
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
    checkActive(current_time);
    if(mState == ACTIVE){
        std::vector<Inputs::Key> trueFlags;
        trueFlags = flags.getTrueFlags(trueFlags);
        mKey = mFlags.compareFlags(trueFlags);
        if(mKey != NULL) {
            mState = GOOD;
        }
        else mState = MISSED;
    }
}

Inputs::Key Beat::getKey() const{
    return mKey;
}
void Beat::checkActive(const sf::Time &currentTime){
    if(mState == INACTIVE){
        if(currentTime >= mTimestamp && currentTime < mTimestamp + TOLERANCE) mState = ACTIVE;
    }
}