#include "Game.h"

Game* Game::_instance = NULL;

Game* Game::getInstance() {
    if (Game::_instance == NULL)
        Game::_instance = new Game();

    return Game::_instance;
}

Game::Game() {
    _gameState = Uninitialized;
}

Game::Game(const Game&) { }
Game& Game::operator=(const Game&) { return *this; }

Game::~Game() {}

void Game::init() {

    if(_gameState != Uninitialized)
        return;

    _window.create(
        sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP),
        SCREEN_TITLE
    );

    _gameState= Game::ShowingMenu;
    loadAssets();
    initFpsText();

    gameLoop();
}

void Game::gameLoop() {

    while (not isExiting()) {
        //std::cout << "ESTE COMENTARIO ES UNA LOCURA" << std::endl; //WTF
        event();
        update();
        draw();
    }
}

void Game::update() {

    while (_clock.getElapsedTime() < sf::seconds(1/120.0));

    sf::Time deltatime = _clock.restart();

    _stave.update(deltatime),
    updateFpsText(deltatime);
}

void Game::draw() {
    _window.clear(sf::Color::Green);
    _window.draw(_stave);
    _window.draw(_fpsText);
    _window.display();
}

void Game::event() {
    sf::Event event;

    while(_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            end();
        }
        if (event.type == sf::Event::KeyPressed) {
            Inputs::Key key = Inputs::SfmlToGameKey(event.key.code);

            _stave.onKeyPressed(key,0);
        }
        else if (event.type == sf::Event::JoystickButtonPressed) {
            Inputs::Key key = Inputs::SfmlJoystickToGameKey(event.joystickButton.button);
            _stave.onKeyPressed(key,1);
        }
        
    }

}

bool Game::isExiting() { return _gameState == Game::Exiting; }

void Game::exitGame() { _gameState = Exiting; }

void  Game::loadAssets() {
    if (!_font.loadFromFile("resources/font1.ttf")) {
        std::cout << "font error" << std::endl;
    }
}

void Game::initFpsText() {
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

void Game::updateFpsText(const sf::Time& deltatime) {
    float seconds = deltatime.asSeconds();
    float fps     = 1.f / seconds;
    
    _fpsCount  += 1;
    _fpsCount2 += fps;
    _fpsTimer  += seconds;

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

        _fpsCount  = 0;
        _fpsCount2 = 0;
        _fpsTimer  = 0;
    }
}

void Game::end() {
    _window.close();
    _gameState = Exiting;
    _stave.close();

    std::cout << "bye" << std::endl;
}