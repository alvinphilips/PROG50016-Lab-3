#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "IRenderable.h"

#include "TextureAsset.h"

class Sprite: public Component, public IRenderable {
	/// <summary>
	/// Texture Asset this sprite makes use of.
	/// </summary>
	TextureAsset* texAsset = nullptr;
	SDL_Rect bounds = {0, 0, 0, 0};
protected:
	void Destroy() override;
	void Update() override;
	void Render() override;
public:
	Sprite() = default;
	void Load(const json::JSON&) override;
};

#endif