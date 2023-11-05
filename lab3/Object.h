#pragma once

#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "json.hpp"

/// <summary>
/// Object serves as the base class for other classes such as Component, Entity and Asset.
/// </summary>
class Object {
	/// <summary>
	/// Boolean to indicate whether the Object was initialized.
	/// </summary>
	bool initialized;

	/// <summary>
	/// The Object's name.
	/// </summary>
	std::string name;

	/// <summary>
	/// Unique ID of the Object.
	/// </summary>
	int id;

protected:
	Object() = default;
	virtual ~Object() = default;

	/// <summary>
	/// Initialize() is called on an Object to set it up and prepare it for use.
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// Destroy() handles the destruction of an Object, taking care of memory and other aspects.
	/// </summary>
	virtual void Destroy();

public:
	/// <summary>
	/// Load an Object from a JSON node.
	/// </summary>
	/// <param name="node">Const reference to a JSON node.</param>
	virtual void Load(const json::JSON&);

	/// <summary>
	/// Returns whether the Object has had Initialize() called on it.
	/// </summary>
	/// <returns>true if previously initialized, else false.</returns>
	bool IsInitialized() const
	{
		return initialized;
	}

	/// <summary>
	/// Returns the name of the Object.
	/// </summary>
	/// <returns>A string reference to the Object's name.</returns>
	const std::string& GetName() const {
		return name;
	}

	/// <summary>
	/// Returns the ID of the Object.
	/// </summary>
	/// <returns>a non-negative integer that indicates the Object's unique id, or -1 if Object was destroyed.</returns>
	int GetId() const
	{
		return id;
	}
};

#endif