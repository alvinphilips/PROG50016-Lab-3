#include "RenderSystem.h"

#include "utils.h"

void RenderSystem::Initialize() {
	// TODO: Implement
}

void RenderSystem::Destroy() {
	// TODO: Implement
}

void RenderSystem::Update() {
	// TODO: Implement
}

void RenderSystem::Load(std::string& fileName) {
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

	// Set fullscreen boolean
	if (render_settings.hasKey("fullscreen")) {
		fullscreen = render_settings.at("fullscreen").ToBool();
	}
}
