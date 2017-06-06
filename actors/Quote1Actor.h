//
// Created by arnito on 4/06/17.
//

#ifndef BEAT_THE_BEAT_QUOTE1ACTOR_HPP
#define BEAT_THE_BEAT_QUOTE1ACTOR_HPP

#include "../Actor.h"
#include "../entities/Quote.h"

class Scene;
class Quote1Actor : public Actor{
public:
    Quote1Actor(int playerId,Quote &q, Scene &s);
    ~Quote1Actor();
    void update(const sf::Time& deltatime);
    void action(Inputs::Key key);
private:
    Quote *_quote;
};


#endif //BEAT_THE_BEAT_QUOTE1ACTOR_HPP
