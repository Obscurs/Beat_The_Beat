#include "Stave.h"

Stave::Stave() {
	_conductor = new Conductor("resources/cave-story.ogg");
}

Stave::~Stave() {
	for (Note* note : _notes) {
		delete note;
	}

	_notes.clear();
}

void Stave::onKeyPressed(Inputs::Key key) {
	/**
		Loop throug all the notes until either:
			1.- A NO_ACTIVE Note is found
			2.- An ACTIVE Note accepts key
			3.- The end of _notes is reached
	*/

	std::list<Note*>::iterator it = _notes.begin();
	bool noActiveFound = false;
	bool keyAccepted   = false;

	while (it != _notes.end() && !noActiveFound && !keyAccepted) {
		Note* note = (*it);

		noActiveFound = note->getState() == Note::NO_ACTIVE;

		if (noActiveFound == false) {
			note->onKeyPressed(key);

			keyAccepted = note->getActivationKey() == key;
		}

		it++;
	}
}

void Stave::update(const sf::Time& deltatime) {
	/**
		Remove all notes that have already expired
	*/

	const sf::Time currentOffset = _conductor->getCurrentTimestamp();

	std::list<Note*>::iterator it = _notes.begin();
	bool noActiveFound = false;

	while (it != _notes.end() && !noActiveFound) {
		Note* note = (*it);

		noActiveFound = note->getState() == Note::NO_ACTIVE;

		it++;
	}

	if (noActiveFound) {
		_notes.erase(_notes.begin(), it);
	}
}

void Stave::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	// TODO
}

void Stave::addNote(Note* note) {
	_notes.push_back(note);
}