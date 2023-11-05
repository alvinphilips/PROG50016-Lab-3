#pragma once

#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#include "Asset.h"

#include <SDL/SDL_image.h>

class TextureAsset final: public Asset {
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
protected:
	TextureAsset() = default;
	~TextureAsset() override = default;
public:
	void Load(const json::JSON&) override;
	void Destroy() override;
};

#endif