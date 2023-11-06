#pragma once

#include <SDL/SDL_rect.h>

typedef SDL_Point IVec2;
typedef SDL_FPoint Vec2;
typedef SDL_FRect Transform;

inline Vec2& operator += (Vec2& lhs, Vec2 const& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}

inline Vec2& operator -= (Vec2& lhs, Vec2 const& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}

inline Vec2 operator + (Vec2 const& lhs, Vec2 const& rhs) {
	Vec2 out = { lhs.x + rhs.x, lhs.y + rhs.y };

	return out;
}

inline Vec2 operator - (Vec2 const& lhs, Vec2 const& rhs) {
	Vec2 out = { lhs.x - rhs.x, lhs.y - rhs.y };

	return out;
}

inline Vec2 operator * (Vec2 const& lhs, float const& rhs) {
	Vec2 out = { lhs.x * rhs, lhs.y * rhs };

	return out;
}

inline Vec2 operator / (Vec2 const& lhs, float const& rhs) {
	float inv_rhs = (float) (1.0 / (double) rhs);

	return lhs * inv_rhs;
}

inline IVec2& operator += (IVec2& lhs, IVec2 const& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}

inline IVec2& operator -= (IVec2& lhs, IVec2 const& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}

inline IVec2 operator + (IVec2 const& lhs, IVec2 const& rhs) {
	IVec2 out = { lhs.x + rhs.x, lhs.y + rhs.y };

	return out;
}

inline IVec2 operator - (IVec2 const& lhs, IVec2 const& rhs) {
	IVec2 out = { lhs.x - rhs.x, lhs.y - rhs.y };

	return out;
}

inline IVec2 operator * (IVec2 const& lhs, int const& rhs) {
	IVec2 out = { lhs.x * rhs, lhs.y * rhs };

	return out;
}

inline IVec2 operator / (IVec2 const& lhs, int const& rhs) {
	IVec2 out = { lhs.x / rhs, lhs.y / rhs };

	return out;
}


inline Transform& operator += (Transform& lhs, Vec2 const& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}

inline Transform& operator -= (Transform& lhs, Vec2 const& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}