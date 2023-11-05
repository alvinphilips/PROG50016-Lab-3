#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <list>
#include "Component.h"
#include <SDL/SDL_rect.h>

/// <summary>
/// An Entity defines an object that is a part of the game world.
/// It contains Components and has a transform.
/// </summary>
class Entity : public Object {
	friend class Scene;

	/// <summary>
	/// The list of Components that belong to an Entity.
	/// </summary>
	std::list<Component*> components;

	/// <summary>
	/// The 'transform' of the Entity.
	/// </summary>
	SDL_FRect transform;

protected:
	Entity() = default;
	~Entity() override = default;
	void Initialize() override;
	void Destroy() override;
	virtual void Update();

public:
	/// <summary>
	/// Load an Entity.
	/// </summary>
	void Load(const json::JSON&) override;

	/// <summary>
	/// Add a Component of the given type to the Entity.
	/// </summary>
	/// <param name="_componentType">Type of Component to create.</param>
	/// <returns></returns>
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