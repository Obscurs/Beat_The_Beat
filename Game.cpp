#include <stdio.h>
#include <math.h>
// TODO: reference additional headers your program requires here
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include <dirent.h>
#include <fstream>
#include <sys/stat.h>
#include <string.h>

#include <limits.h>
#include <unistd.h>
#include <unistd.h>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "Game.h"

Game::Game():
        window()
{
    _gameState = Uninitialized;

}
Game::~Game(){

}

void Game::Init(void)
{

    if(_gameState != Uninitialized)
        return;

    window.create(sf::VideoMode(1024,1024,32),"Beat the beat!");

    _gameState= Game::ShowingMenu;
    sf::Clock clock1;
    sf::Clock clock2;
    float lastTime = 0;

    char c[10];
    sf::Text text;
    sf::Font font;
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::String str("no data");
    text.setString(str);

    if (!font.loadFromFile("resources/font1.ttf"))
    {
        std::cout << "font error" << std::endl;
    }
    text.setFont(font); // font is a sf::Font
    float fps_timer=0;
    int fps_count=0;
    int fps_count2=0;

    while(!IsExiting())
    {
        double delta =  clock1.restart().asSeconds();


        float currentTime = clock2.restart().asSeconds();
        float fps = 1.f / currentTime;
        fps_count += 1;
        fps_count2 += fps;
        lastTime = currentTime;

        window.clear(sf::Color(0,255,0));
        GameLoop(delta);
        fps_timer += lastTime;
        sf::View currentView = window.getView();
        sf::Vector2f centerView = currentView.getCenter();
        sf::Vector2f sizeView = currentView.getSize();
        text.setPosition(centerView.x-sizeView.x/2, centerView.y-sizeView.y/2);
        if(fps_timer > 1){
            sprintf(c, "%i", fps_count2/fps_count);
            std::string string(c);
            sf::String str(string);
            text.setString(str);

            fps_count = 0;
            fps_count2 = 0;
            fps_timer = 0;
        }

        window.draw(text);
        window.display();
    }

    window.close();
}

bool Game::IsExiting()
{
    if(_gameState == Game::Exiting)
        return true;
    else
        return false;
}




void Game::GameLoop(double delta)
{

    sf::Event currentEvent;
    switch(_gameState)
    {
        case Game::ShowingMenu:
        {

            while(window.pollEvent(currentEvent))
            {
                if (
                         (currentEvent.type == sf::Event::KeyPressed) &&
                          (currentEvent.key.code == sf::Keyboard::Escape))
                {
                    std::cout << "bye" << std::endl;
                    Game::ExitGame();
                }

            }
            //Update();
            //Draw();
            break;
        }

    }
}



void Game::ExitGame()
{
    _gameState = Exiting;
}




