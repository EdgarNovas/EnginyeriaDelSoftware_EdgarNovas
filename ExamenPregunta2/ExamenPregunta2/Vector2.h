#pragma once
class Vector2
{
public:
	float x;
	float y;

	Vector2(float x, float y);
	float CalculateDistance(Vector2 other);
};