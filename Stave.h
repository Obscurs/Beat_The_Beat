#ifndef STAVE_HPP
#define STAVE_HPP

#include "GameObject.h"
#include "Note.h"
#include "Conductor.h"

/**
	Class: Stave
	In music, staves are used to represent music compositions.
	This class has a similar role. It holds a set of Notes that activate at a 
	given time expecting the player to respond to them.
*/
class Stave : public GameObject {
public:
	Stave();
	~Stave();

	void onKeyPressed(Inputs::Key key) final;

	void update(const sf::Time& deltatime) final;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

	void addNote(Note* note);

private:
	Conductor* _conductor;

	/**
		Notes are sorted by timestamp. Therefore, if the i-th Note is NO_ACTIVE,
		every j-th Note will be too (i < j)
	*/
	std::list<Note*> _notes;
};

#endif