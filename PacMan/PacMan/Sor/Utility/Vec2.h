#ifndef VEC2_H_
#define VEC2_H_

#ifndef VEC_H_
#define VEC_H_
/**
*@brief int型変数を持つVec型構造体
*/

#define VEC_SIZE int

struct Vec
{
	VEC_SIZE x;
	VEC_SIZE y;

	Vec()
	{
		x = 0;
		y = 0;
	}

	Vec(VEC_SIZE x_, VEC_SIZE y_)
	{
		x = x_;
		y = y_;
	}

};


#endif

#endif