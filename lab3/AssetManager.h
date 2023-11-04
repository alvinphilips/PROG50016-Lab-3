#pragma once

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <list>

#include "Asset.h"

class AssetManager {
	friend class Engine;
	std::list<Asset*> assets;
	AssetManager() = default;
	~AssetManager() = default;
	AssetManager(AssetManager const&) = delete;
	AssetManager& operator =(AssetManager &const) = delete;
protected:
	void Initialize();
	void Destroy();
	void Update();
public:
	static AssetManager& Instance() {
		static AssetManager instance;
		return instance;
	}
	void AddAsset(Asset*);
	void RemoveAsset(Asset*);
};

#endif