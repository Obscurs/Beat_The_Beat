#ifndef KEYBOARDINPUTMANAGER_HPP
#define KEYBOARDINPUTMANAGER_HPP

#include "InputManager.h"

class KeyboardInputManager : public InputManager {
public:
	KeyboardInputManager();
	~KeyboardInputManager() final;

	bool acceptedInput(const sf::Event& event) const final;
	Action SfmlToAction(const sf::Event& event) const final;

private:
	/**
		Hash table.
		Maps Action to sf::Keyboard::Key
	*/
	static const sf::Keyboard::Key mKeyMap[NUM_ACTIONS];
};

#endif