//
// Created by arnito on 4/06/17.
//

#include "Quote1Actor.h"
Quote1Actor::Quote1Actor(int player,Quote &q)
        : Actor(player){
    _quote = &q;
}
Quote1Actor::~Quote1Actor(){

}
void Quote1Actor::update(const sf::Time& deltatime) {

}
void Quote1Actor::action(Inputs::Key key, Scene &s){

    if(key == Inputs::Key::LEFT){
        _quote->_speed.x = 70;
        _quote->_facingState = Quote::LEFT;
    } else if(key == Inputs::Key::RIGHT){
        _quote->_speed.x = 70;
        _quote->_facingState = Quote::RIGHT;
    } else if(key == Inputs::Key::DOWN){
        _quote->_facingState = Quote::DOWN;
    } else if(key == Inputs::Key::UP){
        _quote->_facingState = Quote::UP;
    } else if(key == Inputs::Key::JUMP){
        if(_quote->_state==Quote::STANDING){
            _quote->_speed.y = -200;
            _quote->_state = Quote::JUMPING;
        }
        else {
            _quote->_timerBoost = 200;
            _quote->_state = Quote::BOOSTING;
        }
    }
}

