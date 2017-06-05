//
// Created by arnito on 4/06/17.
//

#ifndef BEAT_THE_BEAT_QUOTE_HPP
#define BEAT_THE_BEAT_QUOTE_HPP

#include "../Entity.h"
class Scene;
class Quote : public Entity{
public:
    enum StateEnum {
        STANDING = 0,
        JUMPING,
        BOOSTING,
        FALLING
    };
    enum FacingEnum {
        LEFT = 0,
        RIGHT,
        UP,
        DOWN
    };

    Quote(std::string texture, sf::Vector2f position,sf::Vector2i size, int frame, int id, int damage, int numFrames, Scene &s);
    ~Quote();
    void update(const sf::Time& deltatime, const std::string colisionMap);
    int _facingState;
    int _state;
    sf::Vector2f _speed;
    float _timerBoost;
private:
    float _timerBoostParticle;


    Scene* _scene;

};


#endif //BEAT_THE_BEAT_QUOTE_HPP
