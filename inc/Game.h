#ifndef GAME_HPP
#define GAME_HPP

#include "utils.h"
#include "Scene.h"
#include "Particle.h"

class Game {
public:
	static Game* getInstance();
	~Game();

	void init();
	void end();

	void setBackgroundScene(Scene* scene);

	void addParticle(Particle* particle);

private:
	static const sf::Time FRAME_TIME;

	static Game* mInstance;
	Game();
	Game(const Game&);
	Game& operator=(const Game&);

	sf::RenderWindow mWindow;
	sf::Clock mClock;

	enum GameState : unsigned int {
		UNINITIALIZED,
		RUNNING,
		EXITING
	};
	GameState mCurrentState;

	Scene* mCurrentScene;
	Scene* mBackgroundScene;

	void gameLoop();
	void loadAssets();

	void scene();
	void particles();
	void event();
	void update();
	void draw();

	bool isExiting() const;

	std::list<Particle*> mParticles;
};

#endif