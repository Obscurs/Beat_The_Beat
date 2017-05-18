#include "Stave.h"

Stave::Stave() {
	_conductor = new Conductor("resources/cave-story.ogg");

	addNote(new Note(_conductor, sf::seconds(1.0f), {true,true,false,false}));
	addNote(new Note(_conductor, sf::seconds(2.0f), {true,true,false,false}));
	addNote(new Note(_conductor, sf::seconds(3.0f), {true,true,false,false}));
	addNote(new Note(_conductor, sf::seconds(4.0f), {true,true,false,false}));
	addNote(new Note(_conductor, sf::seconds(5.0f), {true,true,false,false}));
	addNote(new Note(_conductor, sf::seconds(5.5f), {true,true,false,false}));
	addNote(new Note(_conductor, sf::seconds(6.0f), {true,true,false,false}));
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
	/** An unexpected key was pressed (wrong key => fail) */
	if(!keyAccepted) addTextEvent(NoteTextEvent::FAILED);
}

void Stave::update(const sf::Time& deltatime) {

	/** update of textEvents */
	std::list<NoteTextEvent*>::iterator itT = _textEvents.begin();
	while (itT != _textEvents.end()) {
		NoteTextEvent* textEvent = (*itT);
		textEvent->update(deltatime);
		if(!textEvent->isActive()) {
			_textEvents.erase(itT++);
			delete textEvent;
		}
		else{
			itT++;
		}
	}
	/**
		create of text events and delete notes out of time
	*/
	std::list<Note*>::iterator it = _notes.begin();
	while (it != _notes.end()) {
		Note* note = (*it);
		Note::NoteState ns = note->getState();
		if(ns == Note::MISSED) {
			addTextEvent(NoteTextEvent::MISSED);
			_notes.erase(it++);
			delete note;
		}
		else if(ns == Note::GOOD) {
			addTextEvent(NoteTextEvent::GOOD);
			_notes.erase(it++);
			delete note;
		} else{
			it++;
		}

	}


/*	const sf::Time currentOffset = _conductor->getCurrentTimestamp();

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
*/
}

void Stave::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (Note* note : _notes) {
		target.draw(*note);
	}
	for (NoteTextEvent* textEvent : _textEvents) {
		target.draw(*textEvent);
	}
}

void Stave::addNote(Note* note) {
	_notes.push_back(note);
}
void Stave::addTextEvent(NoteTextEvent::NoteType type){
	_textEvents.push_back(new NoteTextEvent(type));
}