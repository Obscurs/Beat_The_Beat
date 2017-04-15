#pragma once
#include "Utils.h"

class Game
{
public:
    Game();
    ~Game();
	void Init();

private:
	void GameLoop(double delta);
	enum GameState { Uninitialized,
					ShowingMenu, Exiting };
	bool IsExiting();
	void ExitGame();
	GameState _gameState;
	sf::RenderWindow window;



};
