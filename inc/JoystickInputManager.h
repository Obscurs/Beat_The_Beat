#ifndef JOYSTICKINPUTMANAGER_HPP
#define JOYSTICKINPUTMANAGER_HPP

#include "InputManager.h"

class JoystickInputManager : public InputManager {
	JoystickInputManager(unsigned int joystickId);
	~JoystickInputManager() final;

	bool acceptedInput(const sf::Event& event) const final;
	Action SfmlToAction(const sf::Event& event) const final;

private:
	/**
		Identifies joystick to look for on an sf::Event
	*/
	const unsigned int mJoystickId;

	/**
		Hash table.
		Maps Action to sf::Joystick button
	*/
	static const unsigned int mButtonMap[NUM_ACTIONS];
};

#endif