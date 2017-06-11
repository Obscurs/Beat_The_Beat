#ifndef STAVE_H
#define STAVE_H

#include "GameObject.h"
#include "Conductor.h"
#include "Note.h"
#include "KeyboardInputManager.h"

class Stave : public GameObject {
public:
	Stave(const Conductor& conductor);
	~Stave() final;

	void event(const sf::Event& event) final;
	void update(const sf::Time& deltatime) final;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

	void addNote(Note* note);

	void setVerticalPosition(float verticalPosition);
	void setHorizontalStartPosition(float horizontalStartPosition);
	void setHorizontalEndPosition(float horizontalEndPosition);
	void setNoteVelocity(float noteVelocity);

	float getVerticalPosition() const;
	float getHorizontalStartPosition() const;
	float getHorizontalEndPosition() const;
	float getNoteVelocity() const;

private:
	static const float DEFAULT_VERTICAL_POSITION;
	static const float DEFAULT_HORIZONTAL_START_POSITION;
	static const float DEFAULT_HORIZONTAL_END_POSITION;
	static const float DEFAULT_NOTE_VELOCITY;

	float mVerticalPosition;
	float mHorizontalStartPosition;
	float mHorizontalEndPosition;
	float mNoteVelocity;

	/**
		Reference to songs conductor
	*/
	const Conductor& mConductor;

	/**
		List of notes ordered by timestamp
	*/
	std::list<Note*> mNotes;

	/**
		Deletes notes with a timestamp previous to the current timestamp minus 
		note tolerance (MISSED and some GOOD)
	*/
	void deleteNonActiveNotes();
};

#endif