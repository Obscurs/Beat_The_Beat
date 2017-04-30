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

void Inputs::update() {
	// Update _lastKeyState
	memcpy(_lastKeyState, _currentKeyState, sizeof(_currentKeyState));
}

void Inputs::event(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed)
		keyPressed(event.key.code);

	else if (event.type == sf::Event::KeyReleased)
		keyReleased(event.key.code);
}


bool Inputs::keyDown(Inputs::Key k) const { return _currentKeyState[k]; }
bool Inputs::keyUp(Inputs::Key k)   const { return not _currentKeyState[k]; }

bool Inputs::keyHit(Inputs::Key k) const {
	return not _lastKeyState[k] and _currentKeyState[k];
}

bool Inputs::keyBreak(Inputs::Key k) const {
	return _lastKeyState[k] and not _currentKeyState[k];
}

void Inputs::keyPressed(const sf::Keyboard::Key &code) {

	// Update _currentKeyState
	unsigned int i;
	for (i = 0; i < NUM_KEYS; ++i) {
		Inputs::Key key = (Inputs::Key) i;
		sf::Keyboard::Key keyboard_key = _keyMap[key];
		if(code == keyboard_key) {
			_currentKeyState[key] = true;
		}

	}
}

void Inputs::keyReleased(const sf::Keyboard::Key &code) {

	// Update _currentKeyState
	unsigned int i;
	for (i = 0; i < NUM_KEYS; ++i) {
		Inputs::Key key = (Inputs::Key) i;
		sf::Keyboard::Key keyboard_key = _keyMap[key];
		if(code == keyboard_key) {
			_currentKeyState[key] = false;
		}

	}
}