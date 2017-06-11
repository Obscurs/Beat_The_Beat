#ifndef TEXTPARTICLE_HPP
#define TEXTPARTICLE_HPP

#include "Particle.h"

class TextParticle : public Particle {
public:
	TextParticle();
	~TextParticle() final;

	void event(const sf::Event& event) final;
	void update(const sf::Time& deltatime) final;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

	bool hasEnded() const final;

	void setText(const std::string& text);
	void setPosition(const sf::Vector2f& position);

private:
	static const float VELOCITY;

	static const sf::Time MAX_LIFE_TIME;
	sf::Time mLifeTime;

	sf::Font mFont;
	std::string mText;

	sf::Vector2f mPosition;
};

#endif