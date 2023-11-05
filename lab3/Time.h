#pragma once

#ifndef TIME_H
#define TIME_H

#include <chrono>

class Time {
	friend class Engine;

	/// <summary>
	/// Current frame number.
	/// </summary>
	int frameCount = 0;

	/// <summary>
	/// Duration between the current and previous frame.
	/// </summary>
	std::chrono::duration<float> deltaTime = std::chrono::duration<float>(0);

	/// <summary>
	/// Previous frame's time.
	/// </summary>
	std::chrono::time_point<std::chrono::system_clock> beginTime;

	/// <summary>
	/// Current frame's time.
	/// </summary>
	std::chrono::time_point<std::chrono::system_clock> endTime;

	/// <summary>
	/// Total duration from the first frame to the current one.
	/// </summary>
	std::chrono::duration<float> totalTime = std::chrono::duration<float>(0);

	Time() = default;
	~Time() = default;
	Time(Time const&) = delete;
	Time& operator =(Time const&) = delete;

protected:
	/// <summary>
	/// Reset Time.
	/// </summary>
	void Initialize();

	/// <summary>
	/// Advance Time by a single frame/tick.
	/// </summary>
	void Update();

public:
	/// <summary>
	/// Returns the Singleton Instance of Time.
	/// </summary>
	/// <returns></returns>
	inline static Time& Instance() {
		static Time instance;
		return instance;
	}

	/// <summary>
	/// Returns the delta time.
	/// </summary>
	/// <returns>A float indicating the time between two consecutive frames.</returns>
	float DeltaTime() const;

	/// <summary>
	/// Returns the total time the game has been running for.
	/// </summary>
	/// <returns>A float indicating how long approximately the application has been running for.</returns>
	float TotalTime() const;

	/// <summary>
	/// Returns the number of frames that have been rendered so far.
	/// </summary>
	/// <returns>The number of frames rendered.</returns>
	int FrameCount() const;
};

#endif