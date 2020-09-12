#ifndef VEC2_H_
#define VEC2_H_

struct Vec2
{
	float X;
	float Y;

	Vec2()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	Vec2(float x, float y)
	{
		X = x;
		Y = y;
	}

};

#endif