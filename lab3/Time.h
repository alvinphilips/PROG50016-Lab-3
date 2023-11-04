#pragma once

#ifndef TIME_H
#define TIME_H

#include <chrono>

class Time {
	friend class Engine;
	int frameCount = 0;
	std::chrono::duration<float> deltaTime = std::chrono::duration<float>(0);
	std::chrono::time_point<std::chrono::system_clock> beginTime;
	std::chrono::time_point<std::chrono::system_clock> endTime;
	std::chrono::duration<float> totalTime = std::chrono::duration<float>(0);
	Time() = default;
	~Time() = default;
	Time(Time& const) = delete;
	Time& operator =(Time& const) = delete;
protected:
	void Initialize();
	void Update();
public:
	inline static Time& Instance() {
		static Time instance;
		return instance;
	}
	float DeltaTime() const;
	float TotalTime() const;
	int FrameCount() const;
};

#endif