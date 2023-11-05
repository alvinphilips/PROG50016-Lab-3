#include "SceneManager.h"

#include <iostream>

void SceneManager::Initialize() {
	// Check if we have an active scene set
	if (activeScene == nullptr) {
		return;
	}

	// TODO: Check if this is the intended behaviour
	activeScene->Initialize();
}

void SceneManager::Destroy() {
	// Reset active scene
	activeScene = nullptr;

	// Destroy all scenes
	for (const auto& scene : scenes) {
		scene->Destroy();
		delete scene;
	}

	// Clear the list of scenes
	scenes.clear();
}

void SceneManager::Update() {
	// Check if we have an active scene set
	if (activeScene == nullptr) {
		return;
	}

	// TODO: Check if this is the intended behaviour
	activeScene->Update();
}

void SceneManager::AddScene(std::string _fileName) {
	// Create a new scene
	const auto scene = new Scene();

	// Load and initialize the scene
	scene->Load(_fileName);
	scene->Initialize();

	// Add the scene to the list of scenes
	scenes.push_back(scene);

	// Add the scene filename and ID to the map
	_sceneNameToId.emplace(_fileName, (int)scenes.size() - 1);
}

void SceneManager::RemoveScene(std::string _fileName) {
	// Check if we have a scene loaded with the given filename
	const auto scene_find = _sceneNameToId.find(_fileName);
	if (scene_find == _sceneNameToId.end()) {
		std::cout << "ERROR: Invalid Scene Name (" << _fileName << "). Cannot Remove Scene." << std::endl;
		return;
	}

	// Get the ID of the scene to remove
	const int id = scene_find->second;
	_ASSERT(id >= 0 && id < (int)scenes.size());

	// Navigate to the correct scene
	auto scene = scenes.begin();
	std::advance(scene, id);

	// Destroy and clean up the scene's memory
	(*scene)->Destroy();
	delete* scene;

	// Remove the scene from the scene list
	scenes.erase(scene);
	_sceneNameToId.erase(_fileName);
}

void SceneManager::SetActiveScene(int _id) {
	// Check if our ID is valid
	if (_id < 0 || _id > (int)scenes.size()) {
		std::cout << "ERROR: Invalid ID (" << _id << "). Cannot Set Active Scene." << std::endl;
		return;
	}

	// Navigate to the correct scene
	auto scene = scenes.begin();
	std::advance(scene, _id);

	// TODO: Should we destroy the currently active scene, if present?

	// Set the scene as the active scene
	activeScene = *scene;
}

Scene* SceneManager::GetActiveScene() const
{
	return activeScene;
}

Entity* SceneManager::FindEntityById(int id) {
	// We do not have an active scene
	if (activeScene == nullptr) {
		return nullptr;
	}

	// Find the Entity with the given ID in the currently active scene
	return activeScene->FindEntityById(id);
}
