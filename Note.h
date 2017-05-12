#ifndef NOTE_HPP
#define NOTE_HPP

#include "GameObject.h"
#include "Conductor.h"

/**
	Class: Note
	Represents an instant where input from the player is expected.
	A Note expects one or more Inputs::Keys at a given time.
	A tolerance measure is defined: TOLERANCE

	If current offset < _timestamp - TOLERANCE
		state = NO_ACTIVE
	If _timestamp - TOLERANCE < current offset < _timestamp + TOLERANCE
		state = ACTIVE

	When a Note is ACTIVE, it expects an input from the player. This input must 
	match one of _expectedInput.

	If a match is found, the Note registers it and its state changes to GOOD

	If _timestamp + TOLERANCE < current offset and no match has been found
		state = MISSED
*/

class Note : public GameObject {
public:
	Note(const Conductor* conductor, const sf::Time& timestamp,
		 const std::vector<bool>& expectedInput);
	~Note();

	void onKeyPressed(Inputs::Key key) final;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

	enum NoteState {
		NO_ACTIVE = 0,
		ACTIVE,
		MISSED,
		GOOD
	};

	/**
		Returns the current state of the Note.
		Check above for more information about NoteSates
	*/
	Note::NoteState getState() const;

	/**
		Alias for Note::getState() == Note::ACTIVE
	*/
	bool isActive() const;

	/**
		If state == GOOD
			Returns the key that activated the Note
		Otherwise
			Returns Inputs::NO_KEY
	*/
	Inputs::Key getActivationKey() const;

	/**
		Returns true if key is an expected input for the note
	*/
	bool isKeyExpected(Inputs::Key key) const;

private:
	static const sf::Time TOLERANCE;

	static const float VERTICAL_POS;
	static const float FINAL_POS;
	static const float VEL;

	const Conductor* _conductor;
	const sf::Time _timestamp;
	const std::vector<bool> _expectedInput;

	Inputs::Key _activationKey;
};

#endif