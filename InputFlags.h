//
// Created by arnito on 21/04/17.
//

#ifndef BEAT_THE_BEAT_INPUTFLAGS_H
#define BEAT_THE_BEAT_INPUTFLAGS_H


#include "Inputs.h"

class InputFlags {
public:
    InputFlags();
    InputFlags(const std::vector<Inputs::Key> &keys);
    ~InputFlags();

    /**
		fills trueFlags with the flags that are true on mFlags
		@param trueFlags, flags to return, must be empty
	*/
    std::vector<Inputs::Key> &getTrueFlags(std::vector<Inputs::Key> &trueFlags);

    /**
		Check if all k true flags are true on mFlags, if true returns the first 
        coincident key else return NULL
        
		@param flags, flags to compare
	*/
    Inputs::Key compareFlags(const std::vector<Inputs::Key> &flags) const;
private:
    /**
       set all flags to false
    */
    void setFlagsToFalse();

    std::map<Inputs::Key, bool> mFlags;
};


#endif //BEAT_THE_BEAT_INPUTFLAGS_H
