#include "Time.h"


void Time::Initialize() {
	// Reset frame count
	frameCount = 0;

	// Reset delta and total time
	deltaTime = std::chrono::duration<float>(0);
	totalTime = std::chrono::duration<float>(0);

	beginTime = std::chrono::system_clock::now();
	endTime = beginTime;
}

void Time::Update() {
	deltaTime = endTime - beginTime;
	beginTime = endTime;
	totalTime += deltaTime;
	frameCount++;
	endTime = std::chrono::system_clock::now();
}

float Time::DeltaTime() const {
	return deltaTime.count();
}

float Time::TotalTime() const {
	return totalTime.count();
}

int Time::FrameCount() const {
	return frameCount;
}

