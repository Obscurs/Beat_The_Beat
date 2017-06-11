#include "Game.h"

Game* Game::mInstance = nullptr;
const sf::Time Game::FRAME_TIME = sf::seconds(1/60.0f);

Game* Game::getInstance() {
	if (Game::mInstance == nullptr)
		Game::mInstance = new Game();

	return Game::mInstance;
}

Game::Game()
	: mCurrentState(UNINITIALIZED), mCurrentScene(nullptr),
	  mBackgroundScene(nullptr) {}

Game::Game(const Game&) {}
Game& Game::operator=(const Game&) { return *this; }

Game::~Game() {
	if (mCurrentScene != nullptr)
		delete mCurrentScene;

	if (mBackgroundScene != nullptr)
		delete mBackgroundScene;

	for (Particle* particle : mParticles)
		delete particle;
	mParticles.clear();
}

void Game::init() {
	if (mCurrentState != UNINITIALIZED) return;
	mCurrentState = RUNNING;

	const sf::VideoMode videoMode(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	mWindow.create(videoMode, SCREEN_TITLE);
	mWindow.setKeyRepeatEnabled(false);
	
	mClock.restart();

	mCurrentScene = Scene::create(Scene::MENU_SCENE);
	mCurrentScene->start();

	loadAssets();
	gameLoop();
}

void Game::end() {
	if (mCurrentScene != nullptr && mCurrentScene->isStarted()) {
		mCurrentScene->end();
		delete mCurrentScene;
	}

	mWindow.close();
}

void Game::setBackgroundScene(Scene* scene) {
	if (mBackgroundScene != nullptr)
		delete mBackgroundScene;
	mBackgroundScene = scene;
}

void Game::addParticle(Particle* particle) {
	mParticles.push_back(particle);
}

void Game::gameLoop() {
	while (isExiting() == false) {
		// Lock framerate
		while (mClock.getElapsedTime() < FRAME_TIME);

		scene();
		particles();
		event();
		update();
		draw();
	}

	end();
}

void Game::loadAssets() {
	// TODO
}

void Game::scene() {
	if (mCurrentScene == nullptr || mCurrentScene->isEnded()) {
		if (mBackgroundScene == nullptr) {
			mCurrentState = EXITING;
		} else {
			if (mCurrentScene != nullptr)
				delete mCurrentScene;

			mCurrentScene = mBackgroundScene;
			mBackgroundScene = nullptr;

			mCurrentScene->start();
		}

	}
}

void Game::particles() {
	std::list<Particle*>::iterator it = mParticles.begin();

	while (it != mParticles.end()) {
		if ((*it)->hasEnded()) {
			delete *it;
			mParticles.erase(it++);
		} else {
			it++;
		}
	}
}

void Game::event() {
	sf::Event event;

	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			mCurrentState = EXITING;

		if (mCurrentScene != nullptr)
			mCurrentScene->event(event);
	}
}

void Game::update() {
	const sf::Time deltatime = mClock.restart();

	if (mCurrentScene != nullptr)
		mCurrentScene->update(deltatime);

	for (Particle* particle : mParticles)
		particle->update(deltatime);
}

void Game::draw() {
	mWindow.clear(sf::Color::Black);

	if (mCurrentScene != nullptr)
		mWindow.draw(*mCurrentScene);

	for (Particle* particle : mParticles)
		mWindow.draw(*particle);

	mWindow.display();
}

bool Game::isExiting() const {
	return mCurrentState == EXITING;
}