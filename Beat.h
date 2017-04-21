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
    Beat(const sf::Time& timespamp, const InputFlags& flags);
    ~Beat();

    sf::Time getTimestamp() const;
    InputFlags getInputFlags() const;

    enum BeatState {
        INACTIVE,       // mTimestamp > CurrentTime + TOLERANCE
        ACTIVE,         // mTimestamp <= CurrentTime + TOLERANCE and not (GOOD or MISSED)
        GOOD,
        MISSED          // mTimestamp < CurrentTime + TOLERANCE and not GOOD
    };

    BeatState getCurrentState() const;

    /**
        If mState == ACTIVE
            If there is an input in flags expected by mFlags
                Update mKey
                Update mState
                Toggle off mFlag of that input
    */
    void update(const sf::Time& current_time, InputFlags& flags);

    Inputs::Key getKey() const;


private:
    static const sf::Time TOLERANCE;

    const sf::Time   mTimestamp;
    const InputFlags mFlags;

    BeatState   mState;
    Inputs::Key mKey; // Key that was pressed while the Beat was ACTIVE
};

#endif //BEAT_THE_BEAT_BEAT_H
