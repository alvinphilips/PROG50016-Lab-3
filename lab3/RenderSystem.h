#pragma once

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <string>
#include <list>
#include <SDL/SDL_render.h>

#include "IRenderable.h"

/// <summary>
/// The RenderSystem handles the creation, rendering and cleanup of a window and renderer.
/// </summary>
class RenderSystem {
	friend class Engine;

	/// <summary>
	/// Pointer to the SDL_Window.
	/// </summary>
	SDL_Window* window = nullptr;

	/// <summary>
	/// Pointer to the SDL_Renderer.
	/// </summary>
	SDL_Renderer* renderer = nullptr;

	/// <summary>
	/// Title of the window.
	/// </summary>
	std::string name;

	/// <summary>
	/// Width of the window.
	/// </summary>
	int width = 1;

	/// <summary>
	/// Height of the window.
	/// </summary>
	int height = 1;

	/// <summary>
	/// Indicates whether the game runs in fullscreen mode.
	/// </summary>
	bool fullscreen = false;

	/// <summary>
	/// Boolean to signal whether the RenderSystem has been previously initialized.
	/// </summary>
	bool initialized = false;

	/// <summary>
	/// List of IRenderables that can draw to the screen.
	/// </summary>
	std::list<IRenderable*> renderables;

	RenderSystem() = default;
	~RenderSystem() = default;
	RenderSystem(RenderSystem const&) = delete;
	RenderSystem& operator =(RenderSystem const&) = delete;

protected:
	void Initialize();
	void Destroy();
	void Update();

	/// <summary>
	/// Load a RenderSystem's settings.
	/// </summary>
	void Load(std::string);

public:
	/// <summary>
	/// Get the RenderSystem Singleton.
	/// </summary>
	/// <returns>A reference to the Singleton instance of RenderSystem.</returns>
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

	void AddRenderable(IRenderable* _renderable) {
		renderables.push_back(_renderable);
	}

	void RemoveRenderable(IRenderable* _renderable) {
		renderables.remove(_renderable);
	}
};

#endif