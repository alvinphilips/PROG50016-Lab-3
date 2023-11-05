#pragma once

#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "IRenderable.h"

class Sprite: public Component, public IRenderable {
protected:
	void Destroy() override;
	void Update() override;
	void Render() override;
public:
	Sprite() = default;
	void Load(const json::JSON&) override;
};

#endif