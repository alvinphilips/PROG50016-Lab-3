#pragma once

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <string>

class RenderSystem {
	friend class Engine;
	std::string name;
	int width = 1;
	int height = 1;
	bool fullscreen = false;
	RenderSystem() = default;
	~RenderSystem() = default;
	RenderSystem(RenderSystem &const) = delete;
	RenderSystem& operator =(RenderSystem &const) = delete;
protected:
	void Initialize();
	void Destroy();
	void Update();
	void Load();
public:
	static RenderSystem& Instance() {
		static RenderSystem instance;
		return instance;
	}
};

#endif