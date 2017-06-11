#include "Scene.h"

#include "MenuScene.h"
#include "TestScene.h"

Scene::Scene()
	: mCurrentState(UNINITIALIZED) {}

Scene::~Scene() {}

void Scene::start() {
	mCurrentState = STARTED;
	onStart();
}

void Scene::end() {
	mCurrentState = ENDED;
	onEnd();
}

bool Scene::isStarted() const {
	return mCurrentState == STARTED;
}

bool Scene::isEnded() const {
	return mCurrentState == ENDED;
}

Scene* Scene::create(SceneType sceneType) {
	switch (sceneType) {
		case MENU_SCENE:
			return new MenuScene();

		case TEST_SCENE:
			return new TestScene();

		default:
			return nullptr;
	}
}