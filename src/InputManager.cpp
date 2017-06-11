#include "InputManager.h"

InputManager::InputManager() {}
InputManager::~InputManager() {}

bool InputManager::acceptedInput(const sf::Event& event) const {
	return false;
}

InputManager::Action InputManager::SfmlToAction(const sf::Event& event) const {
	return NO_ACTION;
}