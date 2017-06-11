#ifndef NOTE_HPP
#define NOTE_HPP

#include "GameObject.h"
#include "Conductor.h"
#include "InputManager.h"
#include "TextParticle.h"
#include "Game.h"
class Stave;

/**
	Class: Note
	Represents an instant where input from the player is expected.
	A Note expects one or more InputManager::Action at a given time.
	A tolerance measure is defined: TOLERANCE
*/
class Note : public GameObject {
public:
	Note(const Stave& stave, const Conductor& conductor, 
		 const sf::Time& timestamp, const std::vector<bool>& expectedInput);
	~Note() final;

	void action(InputManager::Action action);
	void update(const sf::Time& deltatime) final;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

	enum NoteState : unsigned int {
		NO_ACTIVE = 0,
		ACTIVE,
		EARLY,
		GOOD,
		LATE,
		MISSED,
		WRONG
	};

	/**
		Returns the current state of the Note
	*/
	Note::NoteState getCurrentState() const;

	/**
		Alias for Note::getState() == Note::ACTIVE
	*/
	bool isActive() const;

	/**
		If state == GOOD
			Returns the action that activated the Note
		Otherwise
			Returns InputManager::NO_ACTION
	*/
	InputManager::Action getTriggeredAction() const;

	/**
		Returns true if action is an expected input for the note
	*/
	bool isActionExpected(InputManager::Action action) const;

	static const sf::Time TOLERANCE;

	sf::Time getTimestamp() const;

private:
	static const sf::Time GOOD_RANGE;

	const Stave& mStave;
	const Conductor& mConductor;
	const sf::Time mTimestamp;

	const std::vector<bool> mExpectedInput;
	InputManager::Action mTriggeredAction;

	NoteState mCurrentState;

	void displayNoteMessage(const std::string& string) const;
};

#endif