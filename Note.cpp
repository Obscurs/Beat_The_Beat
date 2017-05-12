#include "Note.h"

const sf::Time Note::TOLERANCE = sf::seconds(0.15f);

const float Note::VERTICAL_POS = SCREEN_HEIGHT / 2;
const float Note::FINAL_POS = 0.0f;
const float Note::VEL = 0.5f; // pixel/ms

Note::Note(const Conductor* conductor,
		   const sf::Time& timestamp,
		   const std::vector<bool>& expectedInput)
	: _conductor(conductor),
	  _timestamp(timestamp), 
	  _expectedInput(expectedInput),
	  _activationKey(Inputs::NO_KEY) {}

Note::~Note() {}

void Note::onKeyPressed(Inputs::Key key) {
	if (isActive() && isKeyExpected(key)) {
		_activationKey = key;
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

Note::NoteState Note::getState() const {
	const sf::Time currentOffset = _conductor->getCurrentTimestamp();

	const sf::Time minTimestamp = _timestamp - Note::TOLERANCE;
	const sf::Time maxTimestamp = _timestamp + Note::TOLERANCE;

	if (currentOffset < minTimestamp) {
		return Note::NO_ACTIVE;
	} else if (minTimestamp < currentOffset && currentOffset < maxTimestamp) {
		if (_activationKey == Inputs::NO_KEY) {
			return Note::ACTIVE;
		} else {
			return Note::GOOD;
		}
	} else {
		if (_activationKey == Inputs::NO_KEY) {
			return Note::MISSED;
		} else {
			return Note::GOOD;
		}
	}
}

bool Note::isActive() const { return getState() == Note::ACTIVE; }

Inputs::Key Note::getActivationKey() const { return _activationKey; }

bool Note::isKeyExpected(Inputs::Key key) const {
	unsigned int index = static_cast<unsigned int> (key);
	return _expectedInput[index] == true;
}