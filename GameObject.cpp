//
// Created by arnito on 21/04/17.
//

#include "GameObject.h"

void GameObject::event(const sf::Event& event) {}
void GameObject::update(const sf::Time& deltatime) {}
void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {}

void GameObject::onKeyPressed(Inputs::Key key) {}
void GameObject::onKeyReleased(Inputs::Key key) {}