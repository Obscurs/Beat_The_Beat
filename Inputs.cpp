#include "Inputs.h"

const sf::Keyboard::Key Inputs::_keyMap[NUM_KEYS] = {
	sf::Keyboard::Up,
	sf::Keyboard::Down,
	sf::Keyboard::Left,
	sf::Keyboard::Right,
	sf::Keyboard::Z,
	sf::Keyboard::X,
	sf::Keyboard::Return,
	sf::Keyboard::BackSpace
};

Inputs::Key Inputs::SfmlToGameKey(sf::Keyboard::Key key) {

	unsigned int i;
	for (i = 0; i < NUM_KEYS; ++i) {
		if (Inputs::_keyMap[i] == key)
			return static_cast<Inputs::Key> (i);
	}

	return Inputs::NO_KEY;
}