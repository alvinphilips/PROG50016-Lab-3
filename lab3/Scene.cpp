#include "Scene.h"

void Scene::Initialize() {
	for (const auto& e: entities) {
		e->Initialize();
	}
}

void Scene::Destroy() {
	for (const auto& e: entities) {
		e->Destroy();
		delete e;
	}
	entities.clear();
}

void Scene::Update() {
	for (const auto& e: entities) {
		e->Update();
	}
}

void Scene::Load(std::string fileName) {

}

Entity* Scene::CreateEntity() {
	const auto entity = new Entity();
	entities.push_back(entity);

	return entity;
}

void Scene::RemoveEntity(Entity* _entity) {
	entities.remove(_entity);

	// TODO: Decide if we want to destroy the data
}

Entity* Scene::FindEntityById(int id) {
	// TODO: Implement Finding Entities
	return nullptr;
}