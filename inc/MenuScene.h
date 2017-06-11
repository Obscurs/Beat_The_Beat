#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "Scene.h"
#include "Game.h"

class MenuScene : public Scene {
public:
	MenuScene();
	~MenuScene() final;

	void onStart() final;
	void onEnd() final;

	void event(const sf::Event& event) final;
	void update(const sf::Time& deltatime) final;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

private:
	static const std::string TITLE_TEXT;
	static const std::string PLAY_TEXT;
	static const std::string EXIT_TEXT;

	static const sf::Vector2f TITLE_POSITION;
	static const sf::Vector2f PLAY_POSITION;
	static const sf::Vector2f EXIT_POSITION;

	static const float CURSOR_X;

	static const float TITLE_SIZE;
	static const float ITEM_SIZE;

	sf::Font mFont;
	sf::Texture mCursorTexture;

	enum CursorPosition : unsigned int {
		PLAY,
		EXIT
	};
	CursorPosition mCurrentCursorPosition;

	void drawTexts(sf::RenderTarget& target) const;
	void drawCursor(sf::RenderTarget& target) const;
};

#endif