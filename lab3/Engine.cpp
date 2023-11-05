#include "Engine.h"
#include <SDL/SDL.h>

void Engine::Initialize() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SceneManager::Instance().Initialize();
	AssetManager::Instance().Initialize();
	Time::Instance().Initialize();
	RenderSystem::Instance().Load("RenderSystem.json");
	RenderSystem::Instance().Initialize();
	InputManager::Instance().Initialize();
}

void Engine::Destroy() {
	InputManager::Instance().Destroy();
	RenderSystem::Instance().Destroy();
	SceneManager::Instance().Destroy();
	AssetManager::Instance().Destroy();
	SDL_Quit();
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
