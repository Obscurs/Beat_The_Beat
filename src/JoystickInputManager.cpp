#include "JoystickInputManager.h"

const unsigned int JoystickInputManager::mButtonMap[NUM_ACTIONS] = {
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7
};

JoystickInputManager::JoystickInputManager(unsigned int joystickId)
	: mJoystickId(joystickId) {}

JoystickInputManager::~JoystickInputManager() {}

bool JoystickInputManager::acceptedInput(const sf::Event& event) const {
	if (event.type != sf::Event::JoystickButtonPressed) return false;
	if (event.joystickButton.joystickId != mJoystickId) return false;

	const unsigned int numActions = NUM_ACTIONS;
	for (unsigned int i = 0; i < numActions; ++i)
		if (event.joystickButton.button == mButtonMap[i])
			return true;

	return false;
}

InputManager::Action 
JoystickInputManager::SfmlToAction(const sf::Event& event) const {
	if (acceptedInput(event) == false) return NO_ACTION;

	const unsigned int numActions = NUM_ACTIONS;
	for (unsigned int i = 0; i < numActions; ++i)
		if (event.joystickButton.button == mButtonMap[i])
			return static_cast<Action> (i);

	return NO_ACTION;
}