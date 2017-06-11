#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP

#include "utils.h"
#include "Animation.h"

class AnimatedSprite : public sf::Sprite {
public:
	AnimatedSprite(const sf::Texture& texture, Animation* animation);

	void setAnimation(Animation* animation);

	void update(const sf::Time& deltatime);
private:
	Animation* animation;
};

#endif