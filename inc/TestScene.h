#ifndef TESTSCENE_HPP
#define TESTSCENE_HPP

#include "Scene.h"
#include "Conductor.h"
#include "Stave.h"
#include "StaveParser.h"
#include "Game.h"
#include "Quote.h"

class TestScene : public Scene {
public:
	TestScene();
	~TestScene() final;

	void onStart() final;
	void onEnd() final;

	void event(const sf::Event& event) final;
	void update(const sf::Time& deltatime) final;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

private:
	Conductor mConductor;
	Stave mStave;

	Quote mQuote;
};

#endif