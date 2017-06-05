//
// Created by arnito on 18/05/17.
//

#include "Resources.h"
std::map<std::string, sf::Font> Resources::fontsMap;
std::map<std::string, sf::Shader> Resources::shadersMap;
std::map<std::string, sf::Texture> Resources::texturesMap;
std::map<std::string, sf::Image> Resources::imagesMap;

void printError(std::string s){
    std::cerr << "Resources:: Error loading... " << s << std::endl;
}

void Resources::load() {

    static bool firstTimeLoadingResources = true;
    if(! firstTimeLoadingResources){
        std::cout << "Already loaded, aborting load" << std::endl;
        return;
    }
    firstTimeLoadingResources = false;

    addFont("font","font1.ttf");
    addImage("s_1_c","scene1_colision.png");
    addTexture("s_1_b","scene1_background.png");
    addTexture("s_1_s","test_spritesheet.png");
    std::cout << " Resources Loaded " << std::endl;
}

void Resources::addTexture(std::string key, std::string path){
    if(! texturesMap[key].loadFromFile(TEXTURETPATH+path)) printError(path);
}

void Resources::addImage(std::string key, std::string path){
    if(! imagesMap[key].loadFromFile(TEXTURETPATH+path)) printError(path);
}

void Resources::addShader(std::string key, std::string shader){
    if(sf::Shader::isAvailable() ){
        if (!shadersMap[key].loadFromMemory(shader, sf::Shader::Fragment)) {
            std::cout << "error loading shader" << key << std::endl;
        }
    }
}

void Resources::addFont(std::string key, std::string path){
    if (!fontsMap[key].loadFromFile(FONTPATH+path)) printError(path);
}

sf::Font* Resources::getFont(std::string key){
    return &fontsMap[key];
}

sf::Shader* Resources::getShader(std::string key){
    return &shadersMap[key];
}

sf::Texture* Resources::getTexture(std::string key){
    return &texturesMap[key];
}

sf::Image* Resources::getImage(std::string key){
    return &imagesMap[key];
}
