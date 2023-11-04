#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <list>
#include "Component.h"

class Entity : public Object {
	friend class Scene;
	std::list<Component*> components;
protected:
	Entity() = default;
	~Entity() override = default;
	void Initialize() override;
	void Destroy() override;
	virtual void Update();
public:
	void Load() override;
	Component* CreateComponent(std::string _componentType);
	void RemoveComponent(Component* _component);
};

#endif