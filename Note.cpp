#include "Note.h"

const sf::Time Note::TOLERANCE = sf::seconds(0.25f);

const float Note::VERTICAL_POS = SCREEN_HEIGHT / 16;
const float Note::FINAL_POS = 20.0f;
const float Note::VEL = 0.05f; // pixel/ms

Note::Note(const Conductor* conductor,
		   const sf::Time& timestamp,
		   const std::vector<bool>& expectedInput)
	: _conductor(conductor),
	  _timestamp(timestamp), 
	  _expectedInput(expectedInput) {
	for(int i=0; i< Inputs::NUM_PLAYERS; i++){
		_activationKey[i] = Inputs::NO_KEY;
	}
}

Note::~Note() {}

void Note::onKeyPressed(Inputs::Key key, int player) {
	if (isActive(player) && isKeyExpected(key)) {
		_activationKey[player] = key;
	}
}

void Note::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::CircleShape sprite(5.0f);
	sprite.setFillColor(sf::Color::Blue);

	const sf::Time currentOffset  = _conductor->getCurrentTimestamp();
	const sf::Time timeDifference = _timestamp - currentOffset;

	float x = Note::FINAL_POS + Note::VEL * (timeDifference.asMilliseconds());
	float y = Note::VERTICAL_POS;

	sprite.setPosition(x, y);

	target.draw(sprite);
}

Note::NoteState Note::getState(int player) const {
	const sf::Time currentOffset = _conductor->getCurrentTimestamp();

	const sf::Time minTimestamp = _timestamp - Note::TOLERANCE;
	const sf::Time maxTimestamp = _timestamp + Note::TOLERANCE;

	if (currentOffset < minTimestamp) {
		return Note::NO_ACTIVE;
	} else if (minTimestamp < currentOffset && currentOffset < maxTimestamp) {
		if (_activationKey[player] == Inputs::NO_KEY) {
			return Note::ACTIVE;
		} else {
			return Note::GOOD;
		}
	} else {
		if (_activationKey[player] == Inputs::NO_KEY) {
			return Note::MISSED;
		} else {
			return Note::GOOD;
		}
	}
}

bool Note::isActive(int player) const { return getState(player) == Note::ACTIVE; }

Inputs::Key Note::getActivationKey(int player) const { return _activationKey[player]; }

bool Note::isKeyExpected(Inputs::Key key) const {
	unsigned int index = static_cast<unsigned int> (key);
	return _expectedInput[index] == true;
}

sf::Vector2f Note::getFinalPos() { return { FINAL_POS, VERTICAL_POS }; }