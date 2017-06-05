//
// Created by arnito on 2/06/17.
//

#include "Scene.h"

Scene::Scene(std::string back, std::string colision):
    _view(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT))
{
    _background = back;
    _colision = colision;

}
Scene::~Scene(){

}
void Scene::onKeyPressed(Inputs::Key key, int player) {
    for (Actor* a : _actors) {
        if(a->getPlayerId()==player){
            a->action(key, *this);
        }
    }
}
void Scene::update(const sf::Time& deltatime) {
    std::list<Entity*>::iterator it = _entities.begin();
    while (it != _entities.end()) {
        Entity* e = (*it);
        e->update(deltatime, _colision);
        if(!e->isActive()){
            _entities.erase(it++);
            delete e;
        } else{
            it++;
        }
    }

    for (Actor* a : _actors) {
        a->update(deltatime);
    }
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.setView(_view);
    sf::Sprite sprite(*Resources::getTexture(_background));
    target.draw(sprite);
    for (Entity* e : _entities) {
        target.draw(*e);
    }
}

void Scene::addEntity(Entity* e){
    _entities.push_back(e);
}
void Scene::addActor(Actor* a){
    _actors.push_back(a);
}

sf::Vector2f Scene::getViewPosition(){
    return _view.getCenter();
}
void Scene::setViewPosition(sf::Vector2f pos){
    _view.setCenter(pos);
}