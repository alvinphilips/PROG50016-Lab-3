#include "AssetManager.h"

void AssetManager::Initialize() {
	// TODO: Implement
}

void AssetManager::Destroy() {
	for (auto& a: assets) {
		delete a;
	}
	assets.clear();
}

void AssetManager::Update() {
	// TODO: Implement
}

void AssetManager::AddAsset(Asset* _asset) {
	assets.push_back(_asset);
}

void AssetManager::RemoveAsset(Asset* _asset) {
	assets.remove(_asset);
}
