//
// Created by arnito on 4/06/17.
//

#include "Particle.h"
#include "../Resources.h"
Particle::Particle(std::string texture,sf::Vector2f position, sf::Vector2i size, int frame, int id, int damage, int numFrames)
        : Entity(texture,position,size,frame,id,damage,numFrames){
    _timeMaxSprite = 100;
}
Particle::~Particle(){

}
void Particle::update(const sf::Time& deltatime, const std::string colisionMap){
    //std::cout << "lol" << std::endl;
    Entity::update(deltatime,colisionMap);

    if(_currentKeyframe ==_currentNumFrames-1) _active = false;
}