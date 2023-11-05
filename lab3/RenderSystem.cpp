#include "RenderSystem.h"

#include "utils.h"

void RenderSystem::Initialize() {
	Uint32 window_flags = 0;

	// Set fullscreen flag, if in full screen mode
	if (fullscreen) {
		window_flags |= SDL_WindowFlags::SDL_WINDOW_FULLSCREEN;
	}

	// Create window
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, window_flags);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	initialized = true;
}

void RenderSystem::Destroy() {
	_ASSERT(initialized);

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
}

void RenderSystem::Update() {
	_ASSERT(initialized);

	SDL_RenderClear(renderer);

	for (auto& renderable: renderables) {
		renderable->Render();
	}

	SDL_RenderPresent(renderer);
}

void RenderSystem::Load(std::string fileName) {
	const json::JSON render_settings = utils::give_me_json(fileName.c_str());

	// Set the title of the window
	if (render_settings.hasKey("name")) {
		name = render_settings.at("name").ToString();
	}
	
	// Set the Window's dimensions
	if (render_settings.hasKey("width")) {
		width = render_settings.at("width").ToInt();
	}
	if (render_settings.hasKey("height")) {
		height = render_settings.at("height").ToInt();
	}

	// Set fullscreen flag
	if (render_settings.hasKey("fullscreen")) {
		fullscreen = render_settings.at("fullscreen").ToBool();
	}
}
