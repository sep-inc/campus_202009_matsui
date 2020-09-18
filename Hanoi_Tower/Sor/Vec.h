#ifndef VEC_H_
#define VEC_H_

struct Vec
{
	unsigned __int8 x;
	unsigned __int8 y;

	Vec()
	{
		x = 0;
		y = 0;
	}

	Vec(unsigned __int8 x_, unsigned  __int8 y_)
	{
		x = x_;
		y = y_;
	}

};

#endif