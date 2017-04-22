//
// Created by arnito on 21/04/17.
//

#ifndef BEAT_THE_BEAT_BEAT_H
#define BEAT_THE_BEAT_BEAT_H

#include "Utils.h"
#include "Inputs.h"
#include "InputFlags.h"
class Beat {
public:


    Beat(sf::Time& timespamp, InputFlags& flags);
    ~Beat();

    sf::Time getTimestamp() const;
    InputFlags getInputFlags() const;
    Inputs::Key getKey() const;
    BeatState getCurrentState() const;


    /**
        If mState == ACTIVE
            If there is an input in flags expected by mFlags
                Update mKey
                Update mState
    */
    void update(const sf::Time& current_time, InputFlags& flags);

    enum BeatState {
        INACTIVE,       // mTimestamp > CurrentTime + TOLERANCE
        ACTIVE,         // mTimestamp <= CurrentTime + TOLERANCE and not (GOOD or MISSED)
        GOOD,
        MISSED          // mTimestamp < CurrentTime + TOLERANCE and not GOOD
    };


private:
    /**
		if currentTime is between mTimesamp and mTimestamp + tolerance and mState == INACTIVE, set mState to ACTIVE
		@param currentTime, the current time of the beatStream
	*/
    void checkActive(const sf::Time &currentTime);
    static const sf::Time TOLERANCE = sf::seconds(1.0f);

    const sf::Time   mTimestamp;
    const InputFlags mFlags;

    BeatState   mState;
    Inputs::Key mKey; // Key that was pressed while the Beat was ACTIVE
};

#endif //BEAT_THE_BEAT_BEAT_H
