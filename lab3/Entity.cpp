#include "Entity.h"

void Entity::Initialize() {
	Object::Initialize();

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

	Object::Destroy();
}

void Entity::Load(const json::JSON& entityNode) {
	Object::Load(entityNode);

	// TODO: Implement Entity loading
}

Component* Entity::CreateComponent(std::string _componentType) {
	// TODO: Implement Component Creation
	Component* component = nullptr;

	component->entity = this;

	return component;
}

void Entity::RemoveComponent(Component* _component) {
	components.remove(_component);
}