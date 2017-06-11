#include "Stave.h"

const float Stave::DEFAULT_VERTICAL_POSITION = SCREEN_HEIGHT - 32;
const float Stave::DEFAULT_HORIZONTAL_START_POSITION = SCREEN_WIDTH - 64.0f;
const float Stave::DEFAULT_HORIZONTAL_END_POSITION = 64.0f;
const float Stave::DEFAULT_NOTE_VELOCITY = 0.05f; // pixel/ms

Stave::Stave(const Conductor& conductor)
	: mVerticalPosition(DEFAULT_VERTICAL_POSITION),
	  mHorizontalStartPosition(DEFAULT_HORIZONTAL_START_POSITION),
	  mHorizontalEndPosition(DEFAULT_HORIZONTAL_END_POSITION),
	  mNoteVelocity(DEFAULT_NOTE_VELOCITY),
	  mConductor(conductor) {}

Stave::~Stave() {
	for (Note* note : mNotes)
		delete note;

	mNotes.clear();
}

void Stave::event(const sf::Event& event) {
	KeyboardInputManager manager;
	InputManager::Action action = manager.SfmlToAction(event);

	std::list<Note*>::iterator it = mNotes.begin();
	while (it != mNotes.end() && (*it)->isActive() == false) {
		++it;
	}

	if (it != mNotes.end())
		(*it)->action(action);
}

void Stave::update(const sf::Time& deltatime) {
	for (Note* note : mNotes)
		note->update(deltatime);

	deleteNonActiveNotes();
}

void Stave::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	float width = mHorizontalStartPosition - mHorizontalEndPosition;
	sf::RectangleShape guide({width, 2.0f});
	guide.setPosition(mHorizontalEndPosition, mVerticalPosition);
	guide.setFillColor(sf::Color::White);
	target.draw(guide);

	sf::CircleShape marker(7.0f);
	marker.setOrigin(5.5f, 5.5f);
	marker.setPosition(mHorizontalEndPosition, mVerticalPosition);
	marker.setFillColor(sf::Color::Transparent);
	marker.setOutlineThickness(2);
	marker.setOutlineColor(sf::Color::White);
	target.draw(marker);

	for (Note* note : mNotes)
		target.draw(*note);
}

void Stave::addNote(Note* note) {
	if (note != nullptr)
		mNotes.push_back(note);
}

void Stave::setVerticalPosition(float verticalPosition) {
	mVerticalPosition = verticalPosition;
}

void Stave::setHorizontalStartPosition(float horizontalStartPosition) {
	mHorizontalStartPosition = horizontalStartPosition;
}

void Stave::setHorizontalEndPosition(float horizontalEndPosition) {
	mHorizontalEndPosition = horizontalEndPosition;
}

void Stave::setNoteVelocity(float noteVelocity) {
	mNoteVelocity = noteVelocity;
}

float Stave::getVerticalPosition() const {
	return mVerticalPosition;
}

float Stave::getHorizontalStartPosition() const {
	return mHorizontalStartPosition;
}

float Stave::getHorizontalEndPosition() const {
	return mHorizontalEndPosition;
}

float Stave::getNoteVelocity() const {
	return mNoteVelocity;
}

void Stave::deleteNonActiveNotes() {
	if (mNotes.empty()) return;

	std::list<Note*>::iterator it = mNotes.begin();

	sf::Time maxTimestamp;
	maxTimestamp = mConductor.getCurrentTimestamp();
	maxTimestamp -= 2.0f * Note::TOLERANCE;

	while (it != mNotes.end() && (*it)->getTimestamp() < maxTimestamp) {
		delete (*it);
		++it;
	}

	mNotes.erase(mNotes.begin(), it);
}