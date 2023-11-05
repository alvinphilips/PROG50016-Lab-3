#include "Engine.h"
#include <SDL/SDL.h>

void Engine::Initialize() {
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Initialize the RenderSystem, so we have a working Window
	RenderSystem::Instance().Load("RenderSystem.json");
	RenderSystem::Instance().Initialize();

	// Initialize Input Manager
	InputManager::Instance().Initialize();

	// Initialize Asset Manager
	AssetManager::Instance().Initialize();

	SceneManager::Instance().Initialize();
	Time::Instance().Initialize();
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
