#include "Stave.h"
#include "entities/Quote.h"
#include "entities/Box.h"
#include "actors/Quote1Actor.h"
#include "actors/Ballos1Actor.h"

Stave::Stave() {
	_conductor = new Conductor("resources/cave-story.ogg");

	_scene = new Scene("s_1_b", "s_1_c");
    Box *e = new Box("s_1_s",sf::Vector2f(300,280),sf::Vector2i(64,64),0,0,10,1);
	Quote *e2 = new Quote("s_1_s",sf::Vector2f(620,280),sf::Vector2i(32,32),0,6,0,1, *_scene);
    _scene->addEntity(e);
	_scene->addEntity(e2);
    Quote1Actor *a = new Quote1Actor(0, *e2);
    Ballos1Actor *a2 = new Ballos1Actor(1, *e2);
    _scene->addActor(a);
    _scene->addActor(a2);

    addNote(new Note(_conductor, sf::seconds(0.5f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(1.6f), {true,true,true,true}));
	addNote(new Note(_conductor, sf::seconds(2.7f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(3.8f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(4.9f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(6.0f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(7.1f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(8.2f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(8.425f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(8.65f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(9.3f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(10.4f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(11.5f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(12.6f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(13.7f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(14.8f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(15.9f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(17.0f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(18.1f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(19.2f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(20.3f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(21.4f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(22.5f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(23.6f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(24.7f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(25.8f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(26.9f), {true,true,true,true}));
    addNote(new Note(_conductor, sf::seconds(28.0f), {true,true,true,true}));
}

Stave::~Stave() {
    _conductor->stopSong();
	for (Note* note : _notes) {

		delete note;
	}

	_notes.clear();
}

void Stave::onKeyPressed(Inputs::Key key, int player) {
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

		noActiveFound = (note->getState(player) == Note::NO_ACTIVE || note->getState(player) == Note::GOOD);

		if (noActiveFound == false) {
			note->onKeyPressed(key, player);
			keyAccepted = note->getActivationKey(player) == key;
		}

		it++;
	}
	/** An unexpected key was pressed (wrong key => fail) */
	if(!keyAccepted) addTextEvent(NoteTextEvent::FAILED,player);
    else {
        _scene->onKeyPressed(key,player);
        addTextEvent(NoteTextEvent::GOOD,player);
    }
}

void Stave::update(const sf::Time& deltatime) {

	_scene->update(deltatime);
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
		bool erase = true;
		for(int i=0; i< Inputs::NUM_PLAYERS; i++){
			Note::NoteState ns = note->getState(i);
			if(ns == Note::MISSED) {
				addTextEvent(NoteTextEvent::MISSED,i);
			} else if(ns != Note::GOOD) {
                erase = false;
            }
		}
		if(erase){
			_notes.erase(it++);
			delete note;
		} else{
			it++;
		}
	}

}

void Stave::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::View currentView = target.getView();
	_scene->draw(target, states);

    target.setView(currentView);
	drawNoteFinalPos(target);

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
void Stave::addTextEvent(NoteTextEvent::NoteType type,int player){
	_textEvents.push_back(new NoteTextEvent(type, player));
}
void Stave::close(){

    _conductor->stopSong();

}

void Stave::drawNoteFinalPos(sf::RenderTarget& target) const {
	sf::Vector2f finalPos = Note::getFinalPos();

	sf::CircleShape finalTarget(10.0f);
	finalTarget.setOrigin(5.0f, 5.0f);
	finalTarget.setPosition(finalPos.x, finalPos.y);
	finalTarget.setFillColor(sf::Color::Transparent);
	finalTarget.setOutlineThickness(5.0f);
	finalTarget.setOutlineColor(sf::Color::White);

	target.draw(finalTarget);
}