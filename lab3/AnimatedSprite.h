#pragma once

#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "Sprite.h"
#include "math.h"

/// <summary>
/// Direction the AnimatedSprite's spritestrip is oriented in.
/// </summary>
enum class SpriteDirection: char {
	HORIZONTAL = 0,
	VERTICAL = 1,
};

class AnimatedSprite: public Sprite {
	/// <summary>
	/// Offset to add to the bounds to get the correct Sprite.
	/// </summary>
	IVec2 offset;

	/// <summary>
	/// Index to start on.
	/// </summary>
	unsigned char startIndex = 0;

	/// <summary>
	/// How many frames the AnimatedSprite.
	/// </summary>
	unsigned char count = 1;

	/// <summary>
	/// Direction of the AnimatedSprite.
	/// </summary>
	SpriteDirection direction = SpriteDirection::HORIZONTAL;

	/// <summary>
	/// Frame rate of the animation.
	/// </summary>
	unsigned char fps = 30;
protected:
	void Update() override;

	/// <summary>
	/// Draw a AnimatedSprite to the screen.
	/// </summary>
	void Render() override;

public:
	AnimatedSprite() = default;

	/// <summary>
	/// Load a AnimatedSprite.
	/// </summary>
	void Load(const json::JSON&) override;
};

#endif