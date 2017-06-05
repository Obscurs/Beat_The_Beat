//
// Created by arnito on 2/06/17.
//

#ifndef BEAT_THE_BEAT_ACTOR_HPP
#define BEAT_THE_BEAT_ACTOR_HPP

#include "GameObject.h"
class Scene;
class Actor {
public:
    Actor(int playerId);
    virtual ~Actor();
    virtual void action(Inputs::Key key, Scene &s);
    virtual void update(const sf::Time& deltatime);
    int getPlayerId();

private:
    int _playerID;
    /*
        action(Key)
     */
};


#endif //BEAT_THE_BEAT_ACTOR_HPP
