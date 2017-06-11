#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.h"
#include "InputManager.h"

class Player : public GameObject {
public:
	Player(InputManager* inputManager);
	virtual ~Player();

	virtual void event(const sf::Event& event);

protected:
	InputManager* mInputManager;
	InputManager::Action mCurrentAction;
};

#endif