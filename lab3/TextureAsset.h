#pragma once

#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#include "Asset.h"

#include <SDL/SDL_image.h>

class TextureAsset final: public Asset {
	SDL_Texture* texture = nullptr;

protected:
	TextureAsset() = default;
	~TextureAsset() override = default;

public:
	void Load(const json::JSON&) override;
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