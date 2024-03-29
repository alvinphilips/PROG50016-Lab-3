#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"

// Forward-declare Entity
class Entity;

class Component : public Object {
	friend class Entity;

protected:
	/// <summary>
	/// The Entity this Component belongs to, if any.
	/// </summary>
	Entity* entity = nullptr;

	Component() = default;
	~Component() override = default;
	void Initialize() override;
	void Destroy() override;

	/// <summary>
	/// Update is called on a Component once per frame.
	/// </summary>
	virtual void Update() = 0;

public:
	/// <summary>
	/// Load a Component.
	/// </summary>
	void Load(const json::JSON&) override;
};

#endif