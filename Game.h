#pragma once
#include "Utils.h"
#include "Inputs.h"

class Game {
public:
    Game();
    ~Game();
	void Init();

private:	
	enum GameState {
		Uninitialized,
		ShowingMenu,
		Exiting
	};

	GameState _gameState;
	sf::RenderWindow _window;

	sf::Clock _clock;

	Inputs _inputs;

	sf::Font _font;
	sf::Text _fpsText;
	float _fpsTimer;
	int _fpsCount;
	int _fpsCount2;

	void GameLoop();

	/***/

	void Update();
	void Draw();
	void Event();

	bool IsExiting();
	void ExitGame();

	void LoadAssets();

	void InitFpsText();
	void UpdateFpsText(const sf::Time& deltatime);

	void End();

};
