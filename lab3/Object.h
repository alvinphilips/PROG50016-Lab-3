#pragma once

#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
	bool initialized;
	std::string name;
	int id;
protected:
	Object() = default;
	virtual ~Object() = default;
	virtual void Initialize() = 0;
	virtual void Destroy() = 0;
public:
	virtual void Load() = 0;
	bool IsInitialized() const
	{
		return initialized;
	}
	std::string& GetName() {
		return name;
	}
	int GetId() const
	{
		return id;
	}
};

#endif