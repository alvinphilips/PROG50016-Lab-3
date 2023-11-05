#pragma once

#ifndef ASSET_H
#define ASSET_H

#include "Object.h"

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