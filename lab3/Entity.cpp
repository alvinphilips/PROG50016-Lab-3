#include "Entity.h"

void Entity::Initialize() {
	for (const auto& c: components) {
		c->Initialize();
	}
}

void Entity::Update() {
	for (const auto& c: components) {
		c->Update();
	}
}

void Entity::Destroy() {
	for (auto& c: components) {
		c->Destroy();
		delete c;
	}
	components.clear();
}

void Entity::Load() {
	// TODO: Implement Entity loading
}

Component* Entity::CreateComponent(std::string _componentType) {
	// TODO: Implement Component Creation
	return nullptr;
}

void Entity::RemoveComponent(Component* _component) {
	components.remove(_component);
}