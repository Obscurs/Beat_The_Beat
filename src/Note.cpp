#include "Note.h"
#include "Stave.h"

const sf::Time Note::TOLERANCE = sf::seconds(0.25f);
const sf::Time Note::GOOD_RANGE = 0.25f * Note::TOLERANCE;

Note::Note(const Stave& stave, const Conductor& conductor,
		   const sf::Time& timestamp, const std::vector<bool>& expectedInput)
	: mStave(stave), mConductor(conductor), mTimestamp(timestamp),
	  mExpectedInput(expectedInput), mTriggeredAction(InputManager::NO_ACTION),
	  mCurrentState(Note::NO_ACTIVE)
	  {}

Note::~Note() {}

void Note::action(InputManager::Action action) {
	if (isActive()) {
		mTriggeredAction = action;

		const sf::Time currentOffset = mConductor.getCurrentTimestamp();

		const sf::Time earlyTimestamp = mTimestamp - Note::GOOD_RANGE;
		const sf::Time goodTimestamp = mTimestamp + Note::GOOD_RANGE;

		if (isActionExpected(action)) {
			
			if (currentOffset < earlyTimestamp) {
				mCurrentState = Note::EARLY;
				displayNoteMessage("EARLY");
			} else if (currentOffset < goodTimestamp) {
				mCurrentState = Note::GOOD;
				displayNoteMessage("GOOD");
			} else {
				mCurrentState = Note::LATE;
				displayNoteMessage("LATE");
			}

		} else {
			mCurrentState = Note::WRONG;
			displayNoteMessage("WRONG");
		}
	}
}

void Note::update(const sf::Time& deltatime) {
	if (mCurrentState == Note::MISSED) return;
	if (mCurrentState == Note::EARLY) return;
	if (mCurrentState == Note::GOOD) return;
	if (mCurrentState == Note::LATE) return;

	const sf::Time currentOffset = mConductor.getCurrentTimestamp();

	const sf::Time minTimestamp = mTimestamp - Note::TOLERANCE;
	const sf::Time maxTimestamp = mTimestamp + Note::TOLERANCE;

	if (minTimestamp < currentOffset && currentOffset < maxTimestamp) {
		if (mTriggeredAction == InputManager::NO_ACTION) {
			mCurrentState = Note::ACTIVE;
		}
	} else if(currentOffset > maxTimestamp) {
		if (mTriggeredAction == InputManager::NO_ACTION) {
			mCurrentState = Note::MISSED;
			displayNoteMessage("MISSED");
		}
	}
}

void Note::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::CircleShape shape(5.0f);
	shape.setOrigin(2.5f, 2.5f);

	switch (mCurrentState) {
		case Note::NO_ACTIVE:
			shape.setFillColor(sf::Color::White);;
			break;
		case Note::ACTIVE:
			shape.setFillColor(sf::Color::Blue);
			break;

		case Note::EARLY:
			shape.setFillColor(sf::Color::Yellow);
			break;

		case Note::GOOD:
			shape.setFillColor(sf::Color::Green);
			break;

		case Note::LATE:
			shape.setFillColor(sf::Color::Magenta);
			break;
		
		default:
			shape.setFillColor(sf::Color::Red);
			break;

	}

	float startPosition = mStave.getHorizontalStartPosition();
	float endPosition = mStave.getHorizontalEndPosition();
	float velocity = mStave.getNoteVelocity();

	sf::Time remainingTime = mTimestamp - mConductor.getCurrentTimestamp();
	float remainingMilliseconds = remainingTime.asMilliseconds();

	sf::Vector2f position;
	position.x = endPosition + velocity * remainingMilliseconds;
	position.y = mStave.getVerticalPosition();

	if (position.x < startPosition) {
		shape.setPosition(position);
		target.draw(shape);
	}
}

Note::NoteState Note::getCurrentState() const {
	return mCurrentState;
}

bool Note::isActive() const {
	return getCurrentState() == Note::ACTIVE;
}

InputManager::Action Note::getTriggeredAction() const {
	return mTriggeredAction;
}

bool Note::isActionExpected(InputManager::Action action) const {
	if (isActive() == false) return false;

	unsigned int index = static_cast<unsigned int> (action);
	return mExpectedInput[index] == true;
}

sf::Time Note::getTimestamp() const {
	return mTimestamp;
}

void Note::displayNoteMessage(const std::string& string) const {
	TextParticle* textParticle = new TextParticle();
	
	sf::Vector2f textPosition;
	textPosition.x = mStave.getHorizontalEndPosition() - 20.0f;
	textPosition.y = mStave.getVerticalPosition() - 50.0f;
	
	textParticle->setPosition(textPosition);
	textParticle->setText(string);

	Game* game = Game::getInstance();
	game->addParticle(textParticle);
}