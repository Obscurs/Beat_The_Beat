//
// Created by arnito on 4/06/17.
//
#include "Quote.h"
#include "../Resources.h"
#include "../Scene.h"
#include "Particle.h"

Quote::Quote(std::string texture,sf::Vector2f position, sf::Vector2i size, int frame, int id, int damage, int numFrames, Scene &s)
    : Entity(texture,position,size,frame,id,damage,numFrames){

    _speed = sf::Vector2f(0,0);
    _scene = &s;
    _timerBoostParticle = 0;
    _state = FALLING;
    _facingState = DOWN;
}
Quote::~Quote(){

}

void Quote::update(const sf::Time& deltatime, const std::string colisionMap){
    Entity::update(deltatime,colisionMap);
    _scene->setViewPosition(sf::Vector2f(_position.x,_scene->getViewPosition().y));
    if(_timerBoostParticle>0) _timerBoostParticle = std::max((float)0,_timerBoostParticle-deltatime.asMilliseconds());
    sf::Image imageCol(*Resources::getImage(colisionMap));


    bool colBottom = colisionMapBottom(imageCol);
    bool colTop = colisionMapTop(imageCol);
    if(_state != BOOSTING){
        switch(_facingState){
            case LEFT:
                if(!colisionMapLeft(imageCol)) {
                    _position.x -= deltatime.asSeconds() * _speed.x;
                    _animationId = 6;
                    _currentNumFrames = 3;
                    _firstKeyFrame = 0;
                }
                break;
            case RIGHT:
                if(!colisionMapRight(imageCol)) {
                    _position.x += deltatime.asSeconds() * _speed.x;
                    _animationId = 7;
                    _currentNumFrames = 3;
                    _firstKeyFrame = 0;
                }
                break;
            case UP:
                _firstKeyFrame = 5;
                _currentNumFrames = 1;
                break;
            case DOWN:
                _firstKeyFrame = 6;
                _currentNumFrames = 1;
                break;
        }
    }

    switch(_state){
        case STANDING:
            _speed.x = 70;
            if(!colBottom || colisionMapRight(imageCol) || colisionMapLeft(imageCol)) _state = FALLING;
            break;
        case JUMPING:
            if(colTop || _speed.y >0){
                _speed.y = 0;
                _state = FALLING;
            }
            else _speed.y = std::min(_speed.y +180*deltatime.asSeconds(),(float)270);
            _position.y += deltatime.asSeconds()*_speed.y;
            break;
        case FALLING:
            _speed.x = 70;
            if(colBottom){
                _speed.y = 0;
                _state = STANDING;
            }  else{
                _position.y += deltatime.asSeconds()*_speed.y;
                _speed.y = std::min(_speed.y +180*deltatime.asSeconds(),(float)270);
            }

            break;
        case BOOSTING:
            if(_timerBoost >0){
                _timerBoost -= deltatime.asMilliseconds();
                if(_timerBoostParticle==0) {
                    Particle *p = new Particle("s_1_s",
                                               sf::Vector2f(_position.x, _position.y + _sizeSprite.y/2),
                                               sf::Vector2i(32, 32), 0, 8, 0, 4);
                    _scene->addEntity(p);
                    _timerBoostParticle = 5;
                }

            } else{
                _timerBoost = 0;
                _state = JUMPING;
                break;
            }
            if(colBottom){
                _speed.y = 0;
                _state = STANDING;
                break;
            }else if(colTop) {
                _speed.y = 0;
                _state = FALLING;
                break;
            }
            if (colisionMapRight(imageCol) || colisionMapLeft(imageCol)) {
                _speed.x =0;
                _state = FALLING;
            }
            switch(_facingState){
                case LEFT:
                    _speed.x = 300;
                    _speed.y = 0;
                    _position.x -=  deltatime.asSeconds() * _speed.x;
                    _animationId = 6;
                    _currentNumFrames = 1;
                    _firstKeyFrame = 0;
                    break;
                case RIGHT:
                    _speed.x = 300;
                    _speed.y = 0;
                    _position.x += deltatime.asSeconds() * _speed.x;
                    _animationId = 7;
                    _currentNumFrames = 1;
                    _firstKeyFrame = 0;
                    break;
                case UP:
                    _speed.x = 0;
                    _speed.y = -300;
                    _position.y += deltatime.asSeconds() * _speed.y;
                    _firstKeyFrame = 5;
                    _currentNumFrames = 1;
                    break;
                case DOWN:
                    _speed.x = 0;
                    _speed.y = 300;
                    _position.y += deltatime.asSeconds() * _speed.y;
                    _firstKeyFrame = 6;
                    _currentNumFrames = 1;
                    break;
            }
            break;
    }
    setPosition(_position);
}