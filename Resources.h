//
// Created by arnito on 18/05/17.
//

#ifndef BEAT_THE_BEAT_RESOURCES_H
#define BEAT_THE_BEAT_RESOURCES_H

#define TEXTURETPATH "resources/Textures/"
#define FONTPATH "resources/"
#include "Utils.h"
class Resources {
public:
    static void load();

    static sf::Font* getFont(std::string key);
    static sf::Shader* getShader(std::string key);
    static sf::Texture* getTexture(std::string key);

private:

    static std::map<std::string, sf::Font> fontsMap;
    static std::map<std::string, sf::Shader> shadersMap;
    static std::map<std::string, sf::Texture> texturesMap;

    static void addFont(std::string key, std::string path);
    static void addTexture(std::string key, std::string path);
    static void addShader(std::string key, std::string shader);
};


#endif //BEAT_THE_BEAT_RESOURCES_H
