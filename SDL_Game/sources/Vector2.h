#pragma once
#include <cmath>
class Vector2
{
public:
	float x;
	float y;
	Vector2()
		: x(0.0f), y(0.0f){}
	Vector2(float _x, float _y)
		: x(_x), y(_y){}


public:
	inline void Normalize() {
		float lenght = sqrtf(x * x + y * y);
		x /= lenght;
		y /= lenght;
	}

	inline Vector2 operator+(const Vector2& other) {return Vector2(x + other.x, y + other.y);}
	inline Vector2 operator-(const Vector2& other) {return Vector2(x - other.x, y - other.y);	}
	inline Vector2 operator*(const float& value) {
		return Vector2(x * value, y * value);
	}
};