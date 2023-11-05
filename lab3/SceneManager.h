#pragma once

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <map>

#include "Scene.h"

class SceneManager {
	// Not part of the provided UML diagram, however would likely be required
	std::map<std::string, int> _sceneNameToId;
	friend class Engine;
	std::list<Scene*> scenes;
	Scene* activeScene = nullptr;
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(SceneManager const&) = delete;
	SceneManager& operator =(SceneManager const&) = delete;
protected:
	void Initialize();
	void Destroy();
	void Update();
public:
	static SceneManager& Instance() {
		static SceneManager instance;
		return instance;
	}
	void AddScene(std::string);
	void RemoveScene(std::string);
	void SetActiveScene(int);
	Scene* GetActiveScene() const;
	Entity* FindEntityById(int);
};

#endif