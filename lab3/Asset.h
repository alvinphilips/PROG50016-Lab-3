#pragma once

#ifndef ASSET_H
#define ASSET_H

#include "Object.h"

/// <summary>
/// An Asset is a resource that can be loaded and used in the game.
/// </summary>
class Asset: public Object {
	friend class AssetManager;
protected:
	Asset() = default;
	~Asset() override = default;
public:
	/// <summary>
	/// Load an Asset.
	/// </summary>
	void Load(const json::JSON&) override;
};

#endif