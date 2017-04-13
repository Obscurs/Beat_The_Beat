#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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
