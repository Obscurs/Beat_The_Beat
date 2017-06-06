//
// Created by arnito on 2/06/17.
//

#ifndef BEAT_THE_BEAT_ACTOR_HPP
#define BEAT_THE_BEAT_ACTOR_HPP

#include "GameObject.h"
#include "Entity.h"

class Scene;
class Actor {
public:
    Actor(int playerId, Scene &s);
    virtual ~Actor();
    virtual void action(Inputs::Key key);
    virtual void update(const sf::Time& deltatime);
    int getPlayerId();

protected:
    int _playerID;
    Scene *_s;
    std::list<Entity*> _tempEntities;
    /*
        action(Key)
     */
};


#endif //BEAT_THE_BEAT_ACTOR_HPP
