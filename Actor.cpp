//
// Created by arnito on 2/06/17.
//

#include "Actor.h"

Actor::Actor(int playerId){
    _playerID = playerId;
}
Actor::~Actor(){

}
int Actor::getPlayerId(){
    return _playerID;
}
void Actor::update(const sf::Time& deltatime) {

}
void Actor::action(Inputs::Key key, Scene &s){

}