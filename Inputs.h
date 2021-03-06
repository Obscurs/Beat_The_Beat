/**
  Input manager
  This class implements an abstaction layer between sf::Keyboard::Key and the 
  game's input buttons. With this, the game logic works with 'ACCEPT' or 'START' 
  buttons, while the Input class translates these to the 'a' or 'Return' keys
*/

#pragma once
#include "Utils.h"

class Inputs {

public:
	static const int NUM_PLAYERS = 2;
	enum Key {
		UP = 0,
		DOWN,
		LEFT,
		RIGHT,
		JUMP,
		CANCEL,
		START,
		SELECT,
		NUM_KEYS,
		NO_KEY
	};

	static Inputs::Key SfmlToGameKey(sf::Keyboard::Key key);
	static Inputs::Key SfmlJoystickToGameKey(int button);
private:
	/**
		Contains the translation between Inputs::Key and sf::Keyboard::Key
	*/
	static const sf::Keyboard::Key _keyMap[NUM_KEYS];
};