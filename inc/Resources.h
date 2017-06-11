#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "utils.h"

class Resources {
public:
    static void loadFont(const std::string& key, const std::string& name);
    static void loadTexture(const std::string& key, const std::string& name);
    static void loadImage(const std::string& key, const std::string& name);
    static void loadInput(const std::string& key, const std::string& name);

    static sf::Font* getFont(const std::string& key);
    static sf::Texture* getTexture(const std::string& key);
    static sf::Image* getImage(const std::string& key);
    static std::ifstream* getInput(const std::string& key);

    static bool existsFont(const std::string& key);
    static bool existsTexture(const std::string& key);
    static bool existsImage(const std::string& key);
    static bool existsInput(const std::string& key);

    static void unloadFont(const std::string& key);
    static void unloadTexture(const std::string& key);
    static void unloadImage(const std::string& key);
    static void unloadInput(const std::string& key);

    static void unloadAllFonts();
    static void unloadAllTextures();
    static void unloadAllImages();
    static void unloadAllInputs();
    static void unloadAll();

private:
    static const std::string RESOURCE_DIR;
    static const std::string FONTS_DIR;
    static const std::string TEXTURES_DIR;
    static const std::string IMAGES_DIR;
    static const std::string INPUTS_DIR;

    static std::map<std::string, sf::Font*> mFontsMap;
    static std::map<std::string, sf::Texture*> mTexturesMap;
    static std::map<std::string, sf::Image*> mImagesMap;
    static std::map<std::string, std::ifstream*> mInputsMap;
};


#endif
