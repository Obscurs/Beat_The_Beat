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
	Inputs();
	~Inputs();

	void update();
	void event(const sf::Event& event);

	enum Key {
		UP = 0,
		DOWN,
		LEFT,
		RIGHT,
		ACCEPT,
		CANCEL,
		START,
		SELECT,
		NUM_KEYS,
		NO_KEY
	};

	/**
		Returns true if the key k is beeing held down
		@param k, the key to check
	*/
	bool keyDown(Inputs::Key k) const;

	/**
		Returns true if the key k is not beeing held down
		@param k, the key to check
	*/
	bool keyUp(Inputs::Key k) const;

	/**
		Returns true if the key k has been pressed in the last update
		@param k, the key to check
	*/
	bool keyHit(Inputs::Key k) const;

	/**
		Returns true if the key k has been released in the last update
		@param k, the key to check
	*/
	bool keyBreak(Inputs::Key k) const;

private:
	/**
		Contains the translation between Inputs::Key and sf::Keyboard::Key
	*/
	static const sf::Keyboard::Key _keyMap[NUM_KEYS];

	bool _lastKeyState[NUM_KEYS];
	bool _currentKeyState[NUM_KEYS];

	void keyPressed(const sf::Keyboard::Key &code);
	void keyReleased(const sf::Keyboard::Key &code);
};