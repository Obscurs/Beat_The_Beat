//
// Created by arnito on 18/05/17.
//

#ifndef BEAT_THE_BEAT_NOTETEXTEVENT_H
#define BEAT_THE_BEAT_NOTETEXTEVENT_H

#include "GameObject.h"

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
    bool _isActive;

private:
    float _timeLeft;   /** Time until the text disapear */
    NoteTextEvent::NoteType _noteType;

};


#endif //BEAT_THE_BEAT_NOTETEXTEVENT_H
