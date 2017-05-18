//
// Created by arnito on 18/05/17.
//

#include "Resources.h"
std::map<std::string, sf::Font> Resources::fontsMap;
std::map<std::string, sf::Shader> Resources::shadersMap;
std::map<std::string, sf::Texture> Resources::texturesMap;

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
    std::cout << " Resources Loaded " << std::endl;
}

void Resources::addTexture(std::string key, std::string path){
    if(! texturesMap[key].loadFromFile(TEXTURETPATH+path)) printError(path);
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
