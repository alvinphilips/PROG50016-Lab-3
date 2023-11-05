#pragma once

#ifndef ASSET_H
#define ASSET_H

#include "Object.h"

class Asset: public Object {
	// Not provided in the UML diagram, but needed to allow Assets to be destroyed
	friend class AssetManager;
protected:
	Asset() = default;
	~Asset() override = default;
public:
	void Load(const json::JSON&) override;
};

#endif