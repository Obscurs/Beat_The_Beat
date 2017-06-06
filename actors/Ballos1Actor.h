//
// Created by arnito on 4/06/17.
//

#ifndef BEAT_THE_BEAT_BALLOS1ACTOR_H
#define BEAT_THE_BEAT_BALLOS1ACTOR_H


#include "../Actor.h"
#include "../entities/Quote.h"

class Ballos1Actor : public Actor {
public:
    Ballos1Actor(int playerId,Quote &q, Scene &s);
    ~Ballos1Actor();
    void update(const sf::Time& deltatime);
    void action(Inputs::Key key);
private:
    Quote *_quote;
};


#endif //BEAT_THE_BEAT_BALLOS1ACTOR_H
