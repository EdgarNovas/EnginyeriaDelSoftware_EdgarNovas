#pragma once
#include "Vector2.h"

class AABB {
protected:
	Vector2 topLeft;
	Vector2 size;
public:
	AABB(Vector2 _topLeft, Vector2 _size)
		: topLeft(_topLeft), size(_size){}

	Vector2 GetTopLeft();
	Vector2 GetSize();
	void SetTopLeft(Vector2 basepos);
	void SetSize(Vector2 size);

	bool CheckOverLappingPoint(Vector2 point);
	bool CheckOverLappingAABB(const AABB* other);
};