#include "TextParticle.h"

const float TextParticle::VELOCITY = -0.05f; // px/ms

const sf::Time TextParticle::MAX_LIFE_TIME = sf::seconds(2.0f);

TextParticle::TextParticle()
	: mLifeTime(sf::Time::Zero), mText(""), mPosition({0, 0}) {

	mFont.loadFromFile("res/font.ttf");
}

TextParticle::~TextParticle() {}

void TextParticle::event(const sf::Event& event) {}

void TextParticle::update(const sf::Time& deltatime) {
	if (mLifeTime < MAX_LIFE_TIME) {
		mLifeTime += deltatime;

		mPosition.y += VELOCITY * deltatime.asMilliseconds();
	}
}

void TextParticle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	float timeLeft;

	if (mLifeTime >= MAX_LIFE_TIME)
		timeLeft = 1.0f;
	else
		timeLeft = mLifeTime.asSeconds() / MAX_LIFE_TIME.asSeconds();

	unsigned int alpha =  static_cast<unsigned int> (timeLeft * 255.0f);
	sf::Color color(255, 255, 255, 255 - alpha);

	sf::Text text;
	text.setFont(mFont);
	text.setColor(color);
	text.setScale(0.8f, 0.8f);
	text.setString(mText);
	text.setPosition(mPosition);

	target.draw(text);
}

bool TextParticle::hasEnded() const {
	return mLifeTime >= MAX_LIFE_TIME;
}

void TextParticle::setText(const std::string& text) {
	mText = text;
}

void TextParticle::setPosition(const sf::Vector2f& position) {
	mPosition = position;
}