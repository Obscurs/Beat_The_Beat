//
// Created by arnito on 2/06/17.
//

#include "Entity.h"
#include "Resources.h"
Entity::Entity(std::string texture,sf::Vector2f position, sf::Vector2i size, int frame, int id, int damage, int numFrames){
    _position = position;
    _timeSprite = 0;
    _timeMaxSprite = 10;
    sf::Texture *tex =Resources::getTexture(texture);
    setTexture(*tex);
    _sizeSprite = size;
    _currentKeyframe = frame;
    _animationId = id;
    _damage_collide = damage;
    _currentNumFrames = numFrames;
    _firstKeyFrame = frame;
    _active = true;

}
Entity::~Entity(){

}

bool Entity::colisionMapBottom(sf::Image &image){
    for(int i=(unsigned int)_position.x; i<(unsigned int)_position.x+_sizeSprite.x; i++){
        sf::Vector2i pixel(i, (unsigned int)_position.y+_sizeSprite.y);
        if(pixel.x >=0 && pixel.x < image.getSize().x && pixel.y >=0 && pixel.y < image.getSize().y){
            sf::Color c = image.getPixel(i, (unsigned int)_position.y+_sizeSprite.y);
            if(c == sf::Color::White || c == sf::Color::Red) return true;
        }
    }
    return false;
}
bool Entity::colisionMapTop(sf::Image &image){
    for(int i=(unsigned int)_position.x; i<(unsigned int)_position.x+_sizeSprite.x; i++){
        sf::Color c = image.getPixel(i, (unsigned int)_position.y);
        if(c == sf::Color::White || c == sf::Color::Red) return true;
    }
    return false;
}
bool Entity::colisionMapLeft(sf::Image &image){
    for(int i=(unsigned int)_position.y; i<(unsigned int)_position.y+_sizeSprite.y; i++){
        sf::Color c = image.getPixel((unsigned int)_position.x,i);
        if(c == sf::Color::White || c == sf::Color::Red) return true;
    }
    return false;
}
bool Entity::colisionMapRight(sf::Image &image){
    for(int i=(unsigned int)_position.y; i<(unsigned int)_position.y+_sizeSprite.y; i++){
        sf::Color c = image.getPixel((unsigned int)_position.x+_sizeSprite.x,i);
        if(c == sf::Color::White || c == sf::Color::Red) return true;
    }
    return false;
}

bool Entity::colisionRectangle(sf::Vector2f position, sf::Vector2f size){
    return (_position.x < position.x+size.x &&
            _position.x+_sizeSprite.x > position.x &&
            _position.y > position.y+size.y &&
            _position.y+_sizeSprite.y < position.y);
}
void Entity::update(const sf::Time& deltatime, const std::string colisionMap){
    _timeSprite += deltatime.asMilliseconds();
    std::cout << _currentKeyframe << " "<< _currentNumFrames << " " << _timeSprite << std::endl; //WTF
    if(_timeSprite > _timeMaxSprite){
        _timeSprite -= _timeMaxSprite;
        _currentKeyframe +=1;
        if(_currentKeyframe >= _currentNumFrames){
            _currentKeyframe = _firstKeyFrame;
        }
    }
    setTextureRect(sf::IntRect(_sizeSprite.x*_currentKeyframe,_sizeSprite.y*_animationId,_sizeSprite.x,_sizeSprite.y));
    setPosition(_position);
}
bool Entity::isActive(){
    return _active;
}