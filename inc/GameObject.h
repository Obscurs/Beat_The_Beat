#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "utils.h"

class GameObject : public sf::Drawable {
public:
	GameObject();
	virtual ~GameObject();

	virtual void event(const sf::Event& event);
	virtual void update(const sf::Time& deltatime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif