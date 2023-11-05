#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <list>
#include "Component.h"
#include <SDL/SDL_rect.h>

class Entity : public Object {
	friend class Scene;
private:
	std::list<Component*> components;
	SDL_FRect transform;
protected:
	Entity() = default;
	~Entity() override = default;
	void Initialize() override;
	void Destroy() override;
	virtual void Update();
public:
	void Load(const json::JSON&) override;
	Component* CreateComponent(std::string _componentType);

	/// <summary>
	/// Remove the given Component from the Entity.
	/// </summary>
	/// <param name="_component">Component to remove.</param>
	void RemoveComponent(Component* _component);

	/// <summary>
	/// Get the Entity's transform.
	/// </summary>
	/// <returns>A pointer to the SDL_FRect transform of the entity.</returns>
	const SDL_FRect* GetTransform() {
		return &transform;
	}
};

#endif