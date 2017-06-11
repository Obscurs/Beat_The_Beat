#include "GameObject.h"

GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::event(const sf::Event& event) {}
void GameObject::update(const sf::Time& deltatime) {}
void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {}