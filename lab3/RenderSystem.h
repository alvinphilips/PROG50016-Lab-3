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
	bool initialized = false;
	std::list<IRenderable*> renderables;

	RenderSystem() = default;
	~RenderSystem() = default;
	RenderSystem(RenderSystem const&) = delete;
	RenderSystem& operator =(RenderSystem const&) = delete;

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

	/// <summary>
	/// Get a pointer to our underlying SDL_Renderer.
	/// We're hoping others play nice with out data.
	/// </summary>
	/// <returns>A pointer to an SDL_Renderer.</returns>
	SDL_Renderer* GetRenderer() const {
		_ASSERT(initialized);
		return renderer;
	}
};

#endif