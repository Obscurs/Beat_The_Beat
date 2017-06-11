#include "KeyboardInputManager.h"

const sf::Keyboard::Key KeyboardInputManager::mKeyMap[NUM_ACTIONS] = {
	sf::Keyboard::Up,
	sf::Keyboard::Down,
	sf::Keyboard::Left,
	sf::Keyboard::Right,
	sf::Keyboard::Z,
	sf::Keyboard::X,
	sf::Keyboard::Return,
	sf::Keyboard::Q
};

KeyboardInputManager::KeyboardInputManager() {}
KeyboardInputManager::~KeyboardInputManager() {}

bool KeyboardInputManager::acceptedInput(const sf::Event& event) const {
	if (event.type != sf::Event::KeyPressed) return false;

	const unsigned int numActions = NUM_ACTIONS;
	for (unsigned int i = 0; i < numActions; ++i)
		if (event.key.code == mKeyMap[i])
			return true;

	return false;
}

InputManager::Action 
KeyboardInputManager::SfmlToAction(const sf::Event& event) const {
	if (acceptedInput(event) == false) return NO_ACTION;

	const unsigned int numActions = NUM_ACTIONS;
	for (unsigned int i = 0; i < numActions; ++i)
		if (event.key.code == mKeyMap[i])
			return static_cast<Action> (i);

	return NO_ACTION;
}