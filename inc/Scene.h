#ifndef SCENE_HPP
#define SCENE_HPP

#include "GameObject.h"

class Scene : public GameObject {
public:
	Scene();
	virtual ~Scene();

	void start();
	void end();

	enum SceneState : unsigned int {
		UNINITIALIZED,
		STARTED,
		ENDED
	};

	bool isStarted() const;
	bool isEnded() const;

	virtual void onStart() = 0;
	virtual void onEnd() = 0;

	enum SceneType : unsigned int {
		MENU_SCENE,
		TEST_SCENE
	};
	static Scene* create(SceneType sceneType);

private:
	SceneState mCurrentState;
};

#endif