//
// Created by arnito on 21/04/17.
//

#ifndef BEAT_THE_BEAT_GAMEOBJECT_H
#define BEAT_THE_BEAT_GAMEOBJECT_H

#include "Utils.h"
#include "Inputs.h"

class GameObject : public sf::Drawable {
	virtual void event(const sf::Event& event);
	virtual void update(const sf::Time& deltatime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void onKeyPressed(Inputs::Key key, int player);
	virtual void onKeyReleased(Inputs::Key key, int player);
};


#endif //BEAT_THE_BEAT_GAMEOBJECT_H
