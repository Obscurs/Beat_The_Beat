//
// Created by arnito on 4/06/17.
//

#include "Ballos1Actor.h"
#include "../entities/Box.h"
#include "../Scene.h"
Ballos1Actor::Ballos1Actor(int player,Quote &q)
        : Actor(player){
    _quote = &q;
}
Ballos1Actor::~Ballos1Actor(){

}
void Ballos1Actor::update(const sf::Time& deltatime) {

}
void Ballos1Actor::action(Inputs::Key key, Scene &s){
    sf::Vector2f qpos = _quote->getPosition();
    int dist = rand() % 300;
    if(key == Inputs::Key::LEFT){
        Box*p = new Box("s_1_s", sf::Vector2f(qpos.x-dist, -64), sf::Vector2i(64, 64), 0, 0, 10, 1);
        s.addEntity(p);
    } else if(key == Inputs::Key::RIGHT){
        Box*p = new Box("s_1_s", sf::Vector2f(qpos.x+dist, -64), sf::Vector2i(64, 64), 0, 0, 10, 1);
        s.addEntity(p);
    } else if(key == Inputs::Key::DOWN){
        Box*p = new Box("s_1_s", sf::Vector2f(qpos.x-dist, -64), sf::Vector2i(64, 64), 0, 0, 10, 1);
        s.addEntity(p);
    } else if(key == Inputs::Key::UP){
        Box*p = new Box("s_1_s", sf::Vector2f(qpos.x+dist, -64), sf::Vector2i(64, 64), 0, 0, 10, 1);
        s.addEntity(p);
    }
}