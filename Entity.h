//
// Created by arnito on 2/06/17.
//

#ifndef BEAT_THE_BEAT_ENITITY_HPP
#define BEAT_THE_BEAT_ENITITY_HPP
#include "Utils.h"

class Entity : public sf::Sprite {
public:
    Entity(std::string texture, sf::Vector2f position,sf::Vector2i size, int frame, int id, int damage, int numFrames);
    ~Entity();


    virtual void update(const sf::Time& deltatime, const std::string colisionMap);
    bool isActive();
protected:
    sf::Vector2f _position;
    sf::Vector2i _sizeSprite;
    int _currentKeyframe;
    int _animationId;
    int _damage_collide;
    int _currentNumFrames;
    int _firstKeyFrame;
    float _timeSprite;
    float _timeMaxSprite;
    bool _active;
    virtual bool colisionMapBottom(sf::Image &image);
    virtual bool colisionMapTop(sf::Image &image);
    virtual bool colisionMapLeft(sf::Image &image);
    virtual bool colisionMapRight(sf::Image &image);
    bool colisionRectangle(sf::Vector2f position, sf::Vector2f size);
};


#endif //BEAT_THE_BEAT_ENITITY_HPP
