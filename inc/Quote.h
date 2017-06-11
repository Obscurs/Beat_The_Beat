#ifndef QUOTE_HPP
#define QUOTE_HPP

#include "Player.h"
#include "Animation.h"
#include "AnimatedSprite.h"

class Quote : public Player {
public:
	Quote(InputManager* inputManager);
	~Quote() final;

	void event(const sf::Event& event) final;
	void update(const sf::Time& deltatime) final;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
private:
	sf::Texture mTexture;
	Animation mAnimation;
	AnimatedSprite mSprite;
};

#endif