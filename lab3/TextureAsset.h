#pragma once

#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#include "Asset.h"

#include <SDL/SDL_image.h>

/// <summary>
/// A TextureAsset is an Asset that contains texture data.
/// </summary>
class TextureAsset final: public Asset {
	/// <summary>
	/// A TextureAsset contains a SDL_Texture internally.
	/// </summary>
	SDL_Texture* texture = nullptr;

protected:
	TextureAsset() = default;
	~TextureAsset() override = default;

public:
	/// <summary>
	/// Load a TextureAsset.
	/// </summary>
	void Load(const json::JSON&) override;

	/// <summary>
	/// Destroy a TextureAsset, and free the SDL_Texture it holds.
	/// </summary>
	void Destroy() override;

	/// <summary>
	/// Get the underlying SDL_Texture.
	/// </summary>
	/// <returns>A pointer to the TextureAsset's SDL_Texture.</returns>
	SDL_Texture* GetTexture() const {
		return texture;
	}
};

#endif