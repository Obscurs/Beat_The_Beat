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

Inputs::Inputs() {
	memset(_lastKeyState, 0, sizeof(_lastKeyState));
	memset(_currentKeyState, 0, sizeof(_currentKeyState));
}

Inputs::~Inputs() {}

void Inputs::Update(const sf::Time& deltatime) {
	// Update _lastKeyState
	memcpy(_lastKeyState, _currentKeyState, sizeof(_currentKeyState));

	// Update _currentKeyState
	unsigned int i;
	for (i = 0; i < NUM_KEYS; ++i) {
		Inputs::Key key = (Inputs::Key) i;
		sf::Keyboard::Key keyboard_key = _keyMap[key];

		_currentKeyState[key] = sf::Keyboard::isKeyPressed(keyboard_key);
	}
}

bool Inputs::KeyDown(Inputs::Key k) const { return _currentKeyState[k]; }
bool Inputs::KeyUp(Inputs::Key k)   const { return not _currentKeyState[k]; }

bool Inputs::KeyHit(Inputs::Key k) const {
	return not _lastKeyState[k] and _currentKeyState[k];
}

bool Inputs::KeyBreak(Inputs::Key k) const {
	return _lastKeyState[k] and not _currentKeyState[k];
}

