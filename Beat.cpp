//
// Created by arnito on 21/04/17.
//

#include "Beat.h"

const sf::Time Beat::TOLERANCE = sf::seconds(1.0f);

Beat::Beat(sf::Time& timespamp, InputFlags& flags) :
    mTimestamp(timespamp),
    mFlags(flags)
{
    mKey       = Inputs::NO_KEY;
    mState     = INACTIVE;
}

Beat::~Beat(){}

sf::Time    Beat::getTimestamp()  const { return mTimestamp; }
InputFlags  Beat::getInputFlags() const { return mFlags; }
Inputs::Key Beat::getKey()        const { return mKey; }

Beat::BeatState Beat::getCurrentState() const { return mState; }

void Beat::update(const sf::Time& current_time, InputFlags& flags){
    checkActive(current_time);
    if(mState == ACTIVE){
        std::vector<Inputs::Key> trueFlags;

        trueFlags = flags.getTrueFlags(trueFlags);
        mKey      = mFlags.compareFlags(trueFlags);

        if(mKey != Inputs::NO_KEY) {
            mState = GOOD;
        }
        else mState = MISSED;
    }
}

void Beat::checkActive(const sf::Time &currentTime){
    if(mState == INACTIVE)
        if(currentTime >= mTimestamp && currentTime < mTimestamp + TOLERANCE)
            mState = ACTIVE;
}