#include "Resources.h"

const std::string Resources::RESOURCE_DIR = "res/";
const std::string Resources::FONTS_DIR    = RESOURCE_DIR + "fonts/";
const std::string Resources::TEXTURES_DIR = RESOURCE_DIR + "textures/";
const std::string Resources::IMAGES_DIR   = RESOURCE_DIR + "images/";
const std::string Resources::INPUTS_DIR   = RESOURCE_DIR + "inputs/";

std::map<std::string, sf::Font*> Resources::mFontsMap;
std::map<std::string, sf::Texture*> Resources::mTexturesMap;
std::map<std::string, sf::Image*> Resources::mImagesMap;
std::map<std::string, std::ifstream*> Resources::mInputsMap;

void Resources::loadFont(const std::string& key, const std::string& name) {
    if (existsFont(key))
        unloadFont(key);

    sf::Font* font = new sf::Font();
    if (font->loadFromFile(Resources::FONTS_DIR + name) == true) {
        mFontsMap[key] = font;
    }
}

void Resources::loadTexture(const std::string& key, const std::string& name) {
    if (existsTexture(key))
        unloadTexture(key);

    sf::Texture* texture = new sf::Texture();
    if (texture->loadFromFile(Resources::TEXTURES_DIR + name) == true) {
        mTexturesMap[key] = texture;
    }
}

void Resources::loadImage(const std::string& key, const std::string& name) {
    if (existsImage(key))
        unloadImage(key);

    sf::Image* image = new sf::Image();
    if (image->loadFromFile(Resources::IMAGES_DIR + name) == true) {
        mImagesMap[key] = image;
    }
}

void Resources::loadInput(const std::string& key, const std::string& name) {
    if (existsInput(key))
        unloadInput(key);

    std::ifstream* input = new std::ifstream();
    input->open(Resources::INPUTS_DIR + name);
    if (input->is_open() == true) {
        mInputsMap[key] = input;
    }
}

sf::Font* Resources::getFont(const std::string& key) {
    if (existsFont(key))
        return mFontsMap[key];

    return nullptr;
}

sf::Texture* Resources::getTexture(const std::string& key) {
    if (existsTexture(key))
        return mTexturesMap[key];

    return nullptr;
}

sf::Image* Resources::getImage(const std::string& key) {
    if (existsImage(key))
        return mImagesMap[key];

    return nullptr;
}

std::ifstream* Resources::getInput(const std::string& key) {
    if (existsInput(key))
        return mInputsMap[key];

    return nullptr;
}

bool Resources::existsFont(const std::string& key) {
    return Resources::mFontsMap.find(key) != Resources::mFontsMap.end();
}

bool Resources::existsTexture(const std::string& key) {
    return Resources::mTexturesMap.find(key) != Resources::mTexturesMap.end();
}

bool Resources::existsImage(const std::string& key) {
    return Resources::mImagesMap.find(key) != Resources::mImagesMap.end();
}

bool Resources::existsInput(const std::string& key) {
    return Resources::mInputsMap.find(key) != Resources::mInputsMap.end();
}

void Resources::unloadFont(const std::string& key) {
    if (existsFont(key)) {
        delete mFontsMap[key];
        mFontsMap.erase(key);
    }
}

void Resources::unloadTexture(const std::string& key) {
    if (existsTexture(key)) {
        delete mTexturesMap[key];
        mTexturesMap.erase(key);
    }
}

void Resources::unloadImage(const std::string& key) {
    if (existsImage(key)) {
        delete mImagesMap[key];
        mImagesMap.erase(key);
    }
}

void Resources::unloadInput(const std::string& key) {
    if (existsInput(key)) {
        delete mInputsMap[key];
        mInputsMap.erase(key);
    }
}

void Resources::unloadAllFonts() {
    std::map<std::string, sf::Font*>::iterator it;

    for (it = mFontsMap.begin(); it != mFontsMap.end(); ++it)
        if (it->second != nullptr)
            delete it->second;

    mFontsMap.clear();
}

void Resources::unloadAllTextures() {
    std::map<std::string, sf::Texture*>::iterator it;

    for (it = mTexturesMap.begin(); it != mTexturesMap.end(); ++it)
        if (it->second != nullptr)
            delete it->second;

    mTexturesMap.clear();
}

void Resources::unloadAllImages() {
    std::map<std::string, sf::Image*>::iterator it;

    for (it = mImagesMap.begin(); it != mImagesMap.end(); ++it)
        if (it->second != nullptr)
            delete it->second;

    mImagesMap.clear();
}

void Resources::unloadAllInputs() {
    std::map<std::string, std::ifstream*>::iterator it;

    for (it = mInputsMap.begin(); it != mInputsMap.end(); ++it)
        if (it->second != nullptr)
            delete it->second;

    mInputsMap.clear();
}

void Resources::unloadAll() {
    unloadAllFonts();
    unloadAllTextures();
    unloadAllImages();
    unloadAllInputs();
}