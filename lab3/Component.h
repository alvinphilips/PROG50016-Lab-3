#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"

class Component : public Object {
	friend class Entity;
protected:
	Component() = default;
	~Component() override = default;
	void Initialize() override;
	void Destroy() override;
	virtual void Update() = 0;
public:
	void Load(const json::JSON&) override;
};

#endif