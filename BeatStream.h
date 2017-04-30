//
// Created by arnito on 21/04/17.
//

#ifndef BEAT_THE_BEAT_BEATSTREAM_H
#define BEAT_THE_BEAT_BEATSTREAM_H

#include "GameObject.h"
#include "Beat.h"
#include "InputFlags.h"
#include <list>

class BeatStream : public GameObject {
public:
    BeatStream();
    ~BeatStream();

    void readBeats(const std::string& filename);

    void update(const sf::Time& deltatime) final;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

    std::list<Beat*>::iterator getFailedBeats();
    std::list<Beat*>::iterator getGoodBeats();

private:
    std::list<Beat*> mBeats;
    std::list<Beat*> mFailedBeats;
    std::list<Beat*> mGoodBeats;

    InputFlags getInputFlags() const;
    void updateBeats();
};


#endif //BEAT_THE_BEAT_BEATSTREAM_H
