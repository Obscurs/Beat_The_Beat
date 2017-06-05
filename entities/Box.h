//
// Created by arnito on 4/06/17.
//

#ifndef BEAT_THE_BEAT_BOX_HPP
#define BEAT_THE_BEAT_BOX_HPP


#include "../Entity.h"

class Box : public Entity{
public:
    Box(std::string texture, sf::Vector2f position,sf::Vector2i size, int frame, int id, int damage, int numFrames);
    ~Box();
    void update(const sf::Time& deltatime, const std::string colisionMap);
private:
    bool colisionMapBottom(sf::Image &image);
    static const int UP_AMOUNT = 30;
    bool _touched_floor;
    bool _reached_up;
    int _upY;
};


#endif //BEAT_THE_BEAT_BOX_HPP
