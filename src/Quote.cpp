#include "Quote.h"

Quote::Quote(InputManager* inputManager)
	: Player(inputManager), mSprite(mTexture, &mAnimation) {

	mTexture.loadFromFile("res/quote.png");

	mAnimation.addFrame({  0,  0, 16, 16 });
	mAnimation.addFrame({ 16,  0, 16, 16 });
	mAnimation.addFrame({  0,  0, 16, 16 });
	mAnimation.addFrame({ 32,  0, 16, 16 });
	mAnimation.setFrameTime(sf::seconds(1/5.0f));
	mAnimation.play();
}

Quote::~Quote() {}

void Quote::event(const sf::Event& event) {}

void Quote::update(const sf::Time& deltatime) {
	mSprite.update(deltatime);
}

void Quote::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(mSprite);
}