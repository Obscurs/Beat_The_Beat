//
// Created by arnito on 21/04/17.
//

#include "BeatStream.h"

BeatStream::BeatStream(){

}

BeatStream::~BeatStream(){

}

void BeatStream::readBeats(const std::string& filename) {

}

void BeatStream::update(const sf::Time& deltatime) {

}
void BeatStream::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}

std::list<Beat*>::iterator BeatStream::getFailedBeats(){

}
std::list<Beat*>::iterator BeatStream::getGoodBeats(){

}

void BeatStream::updateBeats() {
    /*
    std::list<Beat*>::iterator it = mBeats.begin();
    Beat* beat = (*it);

    // Move Failed beats to mFailedBeats
    while (beat->getCurrentState() == Beat::MISSED) ++it;
    mBeats.splice(mFailedBeats.end(),mFailedBeats, mBeats.begin(), it);

    InputFlags flags   = getInputFlags();
    sf::Time timestamp = Game::getConductor()->getCurrentTimestamp();

    // Update Active beats
    bool isActive = true;
    while (isActive && it != mBeats.end()) {
        beat = (*it);
        beat->update(timestamp, flags);

        isActive = beat->getCurrentState() == Beat::ACTIVE;
        ++it;
    }
    */
}

InputFlags BeatStream::getInputFlags() const {
    //TO DO
}