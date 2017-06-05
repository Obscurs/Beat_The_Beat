//
// Created by arnito on 4/06/17.
//

#ifndef BEAT_THE_BEAT_PARTICLE_H
#define BEAT_THE_BEAT_PARTICLE_H


#include "../Entity.h"

class Particle : public Entity{
public:
    Particle(std::string texture, sf::Vector2f position,sf::Vector2i size, int frame, int id, int damage, int numFrames);
    ~Particle();
    void update(const sf::Time& deltatime, const std::string colisionMap);
};


#endif //BEAT_THE_BEAT_PARTICLE_H
