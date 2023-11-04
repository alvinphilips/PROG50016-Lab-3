#pragma once

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

class InputManager {
	friend class Engine;
	InputManager() = default;
	~InputManager() = default;
	InputManager(InputManager &const) = delete;
	InputManager& operator =(InputManager &const) = delete;
protected:
	void Initialize();
	void Destroy();
	void Update();
public:
	static InputManager& Instance() {
		static InputManager instance;
		return instance;
	}
};

#endif