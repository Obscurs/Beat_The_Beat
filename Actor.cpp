//
// Created by arnito on 2/06/17.
//

#include "Actor.h"
#include "Scene.h"
Actor::Actor(int playerId, Scene &s){
    _playerID = playerId;
    _s = &s;
}
Actor::~Actor(){

}
int Actor::getPlayerId(){
    return _playerID;
}
void Actor::update(const sf::Time& deltatime) {
    std::list<Entity*>::iterator it = _tempEntities.begin();
    while (it != _tempEntities.end()) {
        Entity* e = (*it);
        _s->addEntity(e);
        _tempEntities.erase(it++);
    }
}
void Actor::action(Inputs::Key key){

}