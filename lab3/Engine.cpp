#include "Engine.h"

void Engine::Initialize() {
	SceneManager::Instance().Initialize();
	AssetManager::Instance().Initialize();
	Time::Instance().Initialize();
	RenderSystem::Instance().Load("RenderSettings.json");
	RenderSystem::Instance().Initialize();
	InputManager::Instance().Initialize();
}

void Engine::Destroy() {
	InputManager::Instance().Destroy();
	RenderSystem::Instance().Destroy();
	SceneManager::Instance().Destroy();
	AssetManager::Instance().Destroy();
}

void Engine::GameLoop() {
	while (!InputManager::Instance().shouldQuit) {
		AssetManager::Instance().Update();
		InputManager::Instance().Update();
		SceneManager::Instance().Update();
		RenderSystem::Instance().Update();
		Time::Instance().Update();
	}
}
