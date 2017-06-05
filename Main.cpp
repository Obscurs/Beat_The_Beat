
#include <stdio.h>
#include <time.h>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <cassert>
#include "Game.h"
#include "Resources.h"

int main(int argc, char** argv)
{
    srand (time(NULL));
    Resources::load();
    Game::getInstance()->init();
}