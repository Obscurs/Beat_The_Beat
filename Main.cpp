
#include <stdio.h>


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <cassert>
#include "Game.h"


int main(int argc, char** argv)
{
    Game::getInstance()->init();
}