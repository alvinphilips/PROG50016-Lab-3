#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "IRenderable.h"

#include "TextureAsset.h"

class Sprite: public Component, public IRenderable {
protected:
	/// <summary>
	/// Texture Asset this sprite makes use of.
	/// </summary>
	TextureAsset* texAsset = nullptr;

	/// <summary>
	/// The bounds of the TextureAsset the Sprite spans.
	/// </summary>
	SDL_Rect bounds = {0, 0, 0, 0};

	void Initialize() override;
	void Destroy() override;
	void Update() override;

	/// <summary>
	/// Draw a Sprite to the screen.
	/// </summary>
	void Render() override;

public:
	Sprite() = default;

	/// <summary>
	/// Load a Sprite.
	/// </summary>
	void Load(const json::JSON&) override;
};

#endif