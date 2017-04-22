#include "Game.h"

Game::Game() {
    _gameState = Uninitialized;
}

Game::~Game() {}

void Game::Init() {

    if(_gameState != Uninitialized)
        return;

    _window.create(
        sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP),
        SCREEN_TITLE
    );

    _gameState= Game::ShowingMenu;
    LoadAssets();
    InitFpsText();

    GameLoop();
}

void Game::GameLoop() {
    while (not IsExiting()) {
        Event();
        Update();
        Draw();
    }
}

void Game::Update() {
    sf::Time deltatime = _clock.restart();
    _inputs.Update();
    UpdateFpsText(deltatime);
}

void Game::Draw() {
    _window.clear(sf::Color::Green);
    _window.draw(_fpsText);
    _window.display();
}

void Game::Event() {
    sf::Event event;

    while(_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            End();
        }
        else if (event.type == sf::Event::KeyPressed) {
            _inputs.KeyPressed(event.key.code);
        }
        else if (event.type == sf::Event::KeyReleased) {
            _inputs.KeyReleased(event.key.code);
        }
    }
}

bool Game::IsExiting() { return _gameState == Game::Exiting; }

void Game::ExitGame() { _gameState = Exiting; }

void  Game::LoadAssets() {
    if (!_font.loadFromFile("resources/font1.ttf")) {
        std::cout << "font error" << std::endl;
    }
}

void Game::InitFpsText() {
    _fpsText.setCharacterSize(24);
    _fpsText.setColor(sf::Color::Red);
    _fpsText.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::String str("no data");
    _fpsText.setString(str);
    
    _fpsText.setFont(_font);

    _fpsTimer  = 0;
    _fpsCount  = 0;
    _fpsCount2 = 0;
}

void Game::UpdateFpsText(const sf::Time& deltatime) {
    float seconds = deltatime.asSeconds();
    float fps = 1.f / seconds;
    
    _fpsCount += 1;
    _fpsCount2 += fps;
    _fpsTimer += seconds;

    sf::View currentView    = _window.getView();
    sf::Vector2f centerView = currentView.getCenter();
    sf::Vector2f sizeView   = currentView.getSize();
    
    _fpsText.setPosition(centerView.x-sizeView.x/2, centerView.y-sizeView.y/2);
    
    char buffer[40];
    if(_fpsTimer > 1){
        sprintf(buffer, "%i", _fpsCount2 / _fpsCount);
        std::string string(buffer);
        sf::String str(string);
        _fpsText.setString(str);

        _fpsCount = 0;
        _fpsCount2 = 0;
        _fpsTimer = 0;
    }
}

void Game::End() {
    _window.close();
    _gameState = Exiting;

    std::cout << "bye" << std::endl;
}