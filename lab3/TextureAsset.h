#pragma once

#ifndef TEXTURE_ASSET_H
#define TEXTURE_ASSET_H

#include "Asset.h"

class TextureAsset final: public Asset {
protected:
	TextureAsset() = default;
	~TextureAsset() override = default;
public:
	void Load() override;
};

#endif