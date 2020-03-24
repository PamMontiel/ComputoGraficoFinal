#pragma once
class Vector2
{
public:
	int a;
	int b;
	float getY();
	float getX();
	void setX(float a);
	void setY(float b);
	Vector2(float a, float b);
	Vector2();
	~Vector2();
};

