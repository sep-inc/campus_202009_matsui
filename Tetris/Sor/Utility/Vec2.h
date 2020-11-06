#ifndef VEC2_H_
#define VEC2_H_
/**
*@brief int型変数を持つVec型構造体
*/

#define VEC_SIZE int

struct Vec2
{
	VEC_SIZE x;
	VEC_SIZE y;

	Vec2()
	{
		x = 0;
		y = 0;
	}

	Vec2(VEC_SIZE x_, VEC_SIZE y_)
	{
		x = x_;
		y = y_;
	}

};


#endif