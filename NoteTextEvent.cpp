//
// Created by arnito on 18/05/17.
//

#include "NoteTextEvent.h"
#include "Resources.h"
NoteTextEvent::NoteTextEvent(NoteTextEvent::NoteType type,int player){
    _noteType = type;
    _isActive = true;
    _timeLeft = 1;
    _player = player;
}

NoteTextEvent::~NoteTextEvent(){

}
void NoteTextEvent::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(_isActive){
        sf::Text text;
        text.setFont(*Resources::getFont("font"));

        text.setColor(sf::Color::Red);
        text.setCharacterSize(20);
        float x;
        float y;
        switch(_noteType){
            case GOOD:
                text.setString("GOOD");
                break;
            case MISSED:
                y = y+20;
                text.setString("MISSED");
                break;
            case FAILED:
                y = y+40;
                text.setString("FAILED");
                break;
        }


        if(_player==0){
            x = 100;
            y = 100+_timeLeft*100;
        } else {
            x = 600;
            y = 100+_timeLeft*100;
        }
        text.setPosition(x, y);

        target.draw(text);
    }

}
bool NoteTextEvent::isActive() const{
    return _isActive;
}
void NoteTextEvent::update(const sf::Time& deltatime) {
    _timeLeft -= deltatime.asSeconds();
    if(_timeLeft < 0) _isActive = false;
}