#include "Player.h"

Player::Player(InputManager* inputManager)
	: mInputManager(inputManager), mCurrentAction(InputManager::NO_ACTION) {}

Player::~Player() {
	if (mInputManager != nullptr)
		delete mInputManager;
}

void Player::event(const sf::Event& event) {
	if (mInputManager != nullptr)
		mCurrentAction = mInputManager->SfmlToAction(event);
}