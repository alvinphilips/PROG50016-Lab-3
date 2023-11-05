#pragma once

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <list>

#include "Asset.h"

/// <summary>
/// The AssetManager class manages the Assets of the game.
/// </summary>
class AssetManager {
	friend class Engine;

	/// <summary>
	/// List of Asset pointers.
	/// </summary>
	std::list<Asset*> assets;

	AssetManager() = default;
	~AssetManager() = default;
	AssetManager(AssetManager const&) = delete;
	AssetManager& operator =(AssetManager const&) = delete;

protected:
	void Initialize();
	void Destroy();
	void Update();

public:
	/// <summary>
	/// Get the AssetManager Singleton.
	/// </summary>
	/// <returns>The Singleton referemce of AssetManager.</returns>
	static AssetManager& Instance() {
		static AssetManager instance;
		return instance;
	}

	/// <summary>
	/// Add an Asset to the asset list.
	/// </summary>
	/// <param name="asset">Asset to add.</param>
	void AddAsset(Asset*);

	/// <summary>
	/// Remove a given Asset.
	/// </summary>
	/// <param name="asset">Asset to remove.</param>
	void RemoveAsset(Asset*);
};

#endif