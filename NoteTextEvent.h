//
// Created by arnito on 18/05/17.
//

#ifndef BEAT_THE_BEAT_NOTETEXTEVENT_H
#define BEAT_THE_BEAT_NOTETEXTEVENT_H

#include "GameObject.h"

/**
	Class: NoteTextEvent
	Represents a text displayed on the window giving you the feedback of the input
    It will only be displayed if the timer "_timeLeft is > 0
*/

class NoteTextEvent : public GameObject{
public:
    enum NoteType {
        GOOD = 0,
        MISSED,
        FAILED
    };

    NoteTextEvent(NoteTextEvent::NoteType type);
    ~NoteTextEvent();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    void update(const sf::Time& deltatime) final;
    bool isActive() const;

private:
    float _timeLeft;   /** Time until the text disapear */
    bool _isActive;
    NoteTextEvent::NoteType _noteType;

};


#endif //BEAT_THE_BEAT_NOTETEXTEVENT_H
