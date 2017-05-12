#ifndef BEAT_THE_BEAT_GAME_H
#define BEAT_THE_BEAT_GAME_H

#include "Utils.h"
#include "Inputs.h"
#include "Stave.h"

class Game {
public:
	static Game* getInstance();
    ~Game();

	void init();

private:
	static Game* _instance;
	Game();
	Game(const Game&);
	Game& operator=(const Game&);

	enum GameState {
		Uninitialized,
		ShowingMenu,
		Exiting
	};

	GameState        _gameState;
	sf::RenderWindow _window;

	sf::Clock _clock;

	Stave _stave;

	sf::Font _font;
	sf::Text _fpsText;

	float    _fpsTimer;
	int      _fpsCount;
	int      _fpsCount2;

	void gameLoop();

	/***/

	void update();
	void draw();
	void event();

	bool isExiting();
	void exitGame();

	void loadAssets();

	void initFpsText();
	void updateFpsText(const sf::Time& deltatime);

	void end();

};
#endif //BEAT_THE_BEAT_GAME_H