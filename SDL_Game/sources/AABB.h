#pragma once
#include "Vector2.h"

class AABB {
protected:
	Vector2 topLeft;
	Vector2 size;
public:
	AABB(Vector2 _topLeft, Vector2 _size)
		: topLeft(_topLeft), size(_size){}

	Vector2 GetTopLeft() { return topLeft; }
	Vector2 GetSize(){return size;}
	void SetTopLeft(Vector2 basepos) { topLeft = basepos; }
	void SetSize(Vector2 size) { this->size = size; }

	bool CheckOverLappingPoint(Vector2 point);
	bool CheckOverLappingAABB(const AABB* other);
};