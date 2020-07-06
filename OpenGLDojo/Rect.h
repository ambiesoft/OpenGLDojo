#pragma once

#include "../glm/glm/glm.hpp"

using namespace glm;
struct Rect
{
	vec2 m_position;
	vec2 m_size;

	Rect(const vec2& position, const vec2& size);
	void Draw();
	bool intersect(const vec2& point);
};

