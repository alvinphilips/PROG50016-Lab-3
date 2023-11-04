#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include "InputManager.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "RenderSystem.h"
#include "Time.h"

class Engine {
	Engine() = default;
	~Engine() = default;
	Engine(Engine &const) = delete;
	Engine& operator =(Engine &const) = delete;
public:
	inline static Engine& Instance() {
		static Engine instance;
		return instance;
	}
	void Initialize();
	void Destroy();
	void GameLoop();
};

#endif