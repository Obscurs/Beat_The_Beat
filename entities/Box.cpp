//
// Created by arnito on 4/06/17.
//

#include "Box.h"
#include "../Resources.h"
Box::Box(std::string texture,sf::Vector2f position, sf::Vector2i size, int frame, int id, int damage, int numFrames)
        : Entity(texture,position,size,frame,id,damage,numFrames){
    _touched_floor = false;
    _reached_up = false;
}
Box::~Box(){

}
bool Box::colisionMapBottom(sf::Image &image){
    for(int i=(unsigned int)_position.x; i<(unsigned int)_position.x+_sizeSprite.x; i++){
        sf::Vector2i pixel(i, (unsigned int)_position.y+_sizeSprite.y);
        if(pixel.x >=0 && pixel.x < image.getSize().x && pixel.y >=0 && pixel.y < image.getSize().y){
            sf::Color c = image.getPixel(i, (unsigned int)_position.y+_sizeSprite.y);
            if(c == sf::Color::White) return true;
        }
    }
    return false;
}
void Box::update(const sf::Time& deltatime, const std::string colisionMap){
    Entity::update(deltatime,colisionMap);

    sf::Image imageCol(*Resources::getImage(colisionMap));

    bool colBottom = colisionMapBottom(imageCol);
    if(colBottom && !_touched_floor){
        _upY = (int)_position.y-UP_AMOUNT;
        _touched_floor = true;
    }
    if(_touched_floor && !_reached_up){
        _position.y -= deltatime.asSeconds()*270;
        if(_position.y <= _upY) _reached_up = true;
    }
    else if(!colBottom || _touched_floor) _position.y += deltatime.asSeconds()*270;

    setPosition(_position);
    if(_position.y>1024) _active = false;
}