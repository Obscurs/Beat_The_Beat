#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "GameObject.h"

class Particle : public GameObject {
public:
	virtual void event(const sf::Event& event) = 0;
	virtual void update(const sf::Time& deltatime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;	

	virtual bool hasEnded() const = 0;
};

#endif