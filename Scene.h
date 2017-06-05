//
// Created by arnito on 2/06/17.
//

#ifndef BEAT_THE_BEAT_SCENE_HPP
#define BEAT_THE_BEAT_SCENE_HPP

#include "GameObject.h"
#include "Resources.h"
#include "Entity.h"
#include "Actor.h"
class Scene : public GameObject {
public:
    Scene(std::string back, std::string colision);
    ~Scene();

    void update(const sf::Time& deltatime) final;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    void onKeyPressed(Inputs::Key key, int player) final;
    void addEntity(Entity* e);
    void addActor(Actor* a);
    sf::Vector2f getViewPosition();
    void setViewPosition(sf::Vector2f pos);
private:
    std::string _background;
    std::string _colision;
    std::list<Actor*> _actors;
    std::list<Entity*> _entities;
    sf::View _view;
};


#endif //BEAT_THE_BEAT_SCENE_HPP
