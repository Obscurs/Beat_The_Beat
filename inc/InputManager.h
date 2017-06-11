#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "utils.h"

/**
	Class: InputManager

	Abstraction layer between input devices and ingame actions
	An instance of this class (or children) is created for each player
*/
class InputManager {
public:
	InputManager();
	virtual ~InputManager();

	/**
		All the actions a player can input regardless of the input device 
		(keyboard or joystick)
	*/
	enum Action : unsigned int {
		UP = 0,
		DOWN,
		LEFT,
		RIGHT,
		JUMP,
		CANCEL,
		START,
		SELECT,
		NUM_ACTIONS,
		NO_ACTION
	};

	/**
		Returns true if the manager expects the input
		If returns false, SfmlToAction should return NO_ACTION
	*/
	virtual bool acceptedInput(const sf::Event& event) const;

	/**
		Parses event and converts it into an Action
		If no action matches, returns NO_ACTION
	*/
	virtual InputManager::Action SfmlToAction(const sf::Event& event) const;
};

#endif