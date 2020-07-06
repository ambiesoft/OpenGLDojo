#include "Rect.h"

#include <GL/glut.h>

Rect::Rect(const vec2& position, const vec2& size) :
	m_position(position),
	m_size(size)
{

}

void Rect::draw()
{
	glRectf(
		m_position.x, m_position.y,
		m_position.x + m_size.x, m_position.y + m_size.y
	);
}
bool Rect::intersect(const vec2& point)
{
	if (
		(point.x >= m_position.x) &&
		(point.x <= (m_position.x + m_size.x)) &&
		(point.y >= m_position.y) &&
		(point.y <= (m_position.y + m_size.y))
		)
		return true;
	return false;
}
bool Rect::intersect(const Rect& rect)
{
	return (
		((m_position.x + m_size.x) >= rect.m_position.x) &&
		(m_position.x <= (rect.m_position.x + rect.m_size.x)) &&
		((m_position.y + m_size.y) >= rect.m_position.y) &&
		(m_position.y <= (rect.m_position.y + rect.m_size.y))
		);
}
