#include "InputManager.h"

#include <SDL/SDL_events.h>

void InputManager::Initialize() {
	shouldQuit = false;
}

void InputManager::Destroy() {
	// TODO: Implement
}

void handleKeyboardEvent(SDL_KeyboardEvent key_event) {
	// TODO: this is a stub
}

void InputManager::Update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_WINDOWEVENT:
			if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
				shouldQuit = true;
			}
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDL_KeyCode::SDLK_ESCAPE) {
				shouldQuit = true;
			} else {
				handleKeyboardEvent(event.key);
			}
			break;
		}
	}
}

bool InputManager::ShouldQuit() const
{
	return shouldQuit;
}