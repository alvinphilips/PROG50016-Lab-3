#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"

class Component : public Object {
	friend class Entity;
protected:
	Component() = default;
	~Component() override = default;
	void Initialize() override = 0;
	void Destroy() override = 0;
	virtual void Update() = 0;
public:
	void Load() override = 0;
};

#endif