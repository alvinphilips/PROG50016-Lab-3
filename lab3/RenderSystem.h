#pragma once

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <string>
#include <list>
#include <SDL/SDL_render.h>

#include "IRenderable.h"

class RenderSystem {
	friend class Engine;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	std::string name;
	int width = 1;
	int height = 1;
	bool fullscreen = false;
	std::list<IRenderable*> renderables;
	RenderSystem() = default;
	~RenderSystem() = default;
	RenderSystem(RenderSystem &const) = delete;
	RenderSystem& operator =(RenderSystem &const) = delete;
protected:
	void Initialize();
	void Destroy();
	void Update();
	void Load(std::string);
public:
	static RenderSystem& Instance() {
		static RenderSystem instance;
		return instance;
	}
};

#endif