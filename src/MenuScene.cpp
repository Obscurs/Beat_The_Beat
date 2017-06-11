#include "MenuScene.h"

const std::string MenuScene::TITLE_TEXT = SCREEN_TITLE;
const std::string MenuScene::PLAY_TEXT = "PLAY";
const std::string MenuScene::EXIT_TEXT = "EXIT";

const sf::Vector2f MenuScene::TITLE_POSITION = { 10.0f, 10.0f };
const sf::Vector2f MenuScene::PLAY_POSITION = { 60.0f, 100.0f };
const sf::Vector2f MenuScene::EXIT_POSITION = { 60.0f, 140.0f };

const float MenuScene::CURSOR_X = { 10.0f };

const float MenuScene::TITLE_SIZE = 2.0f;
const float MenuScene::ITEM_SIZE = 1.0f;

MenuScene::MenuScene()
	: mCurrentCursorPosition(PLAY) {}
MenuScene::~MenuScene() {}

void MenuScene::onStart() {
	mFont.loadFromFile("res/font.ttf");
	mCursorTexture.loadFromFile("res/cursor.png");
}

void MenuScene::onEnd() {}

void MenuScene::event(const sf::Event& event) {
	Scene* playScene;
	Game* game;

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
			case sf::Keyboard::Up:
			case sf::Keyboard::Down:
				if (mCurrentCursorPosition == PLAY)
					mCurrentCursorPosition = EXIT;
				else
					mCurrentCursorPosition = PLAY;
				break;

			case sf::Keyboard::Return:
				if (mCurrentCursorPosition == PLAY) {
					playScene = Scene::create(Scene::TEST_SCENE);
					game = Game::getInstance();
					
					game->setBackgroundScene(playScene);
				}
				
				end();
				break;

			default:
				break;
		}
	}
}

void MenuScene::update(const sf::Time& deltatime) {}

void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	drawTexts(target);
	drawCursor(target);
}

void MenuScene::drawTexts(sf::RenderTarget& target) const {
	sf::Text text;
	text.setFont(mFont);
	text.setColor(sf::Color::White);

	text.setString(TITLE_TEXT);
	text.setScale(TITLE_SIZE, TITLE_SIZE);
	text.setPosition(TITLE_POSITION);
	target.draw(text);

	text.setString(PLAY_TEXT);
	text.setScale(ITEM_SIZE, ITEM_SIZE);
	text.setPosition(PLAY_POSITION);
	target.draw(text);

	text.setString(EXIT_TEXT);
	text.setScale(ITEM_SIZE, ITEM_SIZE);
	text.setPosition(EXIT_POSITION);
	target.draw(text);
}

void MenuScene::drawCursor(sf::RenderTarget& target) const {
	sf::Vector2f cursorPosition;
	cursorPosition.x = CURSOR_X;
	if (mCurrentCursorPosition == PLAY)
		cursorPosition.y = PLAY_POSITION.y;
	else
		cursorPosition.y = EXIT_POSITION.y;

	sf::Sprite cursor(mCursorTexture);
	cursor.setPosition(cursorPosition);
	target.draw(cursor);
}