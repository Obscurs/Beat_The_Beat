#include "TestScene.h"

TestScene::TestScene()
	: mConductor("res/CaveStory.ogg"), mStave(mConductor),
	  mQuote(new KeyboardInputManager()) {}

TestScene::~TestScene() {}

void TestScene::onStart() {
	StaveParser parser(mConductor, mStave, "res/stave0.in");
	parser.parse();
}

void TestScene::onEnd() {}

void TestScene::event(const sf::Event& event) {
	Scene* playScene;
	Game* game;

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
			
			case sf::Keyboard::Escape:
				playScene = Scene::create(Scene::MENU_SCENE);
				game = Game::getInstance();
				
				game->setBackgroundScene(playScene);
				
				end();
				break;

			default:
				break;
		}

		mStave.event(event);
	}
}

void TestScene::update(const sf::Time& deltatime) {
	mStave.update(deltatime);
	mQuote.update(deltatime);
}

void TestScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(mStave);
	target.draw(mQuote);
}