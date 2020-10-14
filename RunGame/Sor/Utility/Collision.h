#include "Vec.h"
#ifndef COLLISION_H_
#define COLLISION_H_

enum EdgeType
{
	TOP,
	BOTTOM,
	LEFT,
	RIGHT
};

struct EdgeInfo
{
	__int8 top;
	__int8 bottom;
	__int8 left;
	__int8 right;
};

class Collision
{
public:
	Collision() {}
	~Collision() {}


	static bool UnderCollision(Vec player_pos_, Vec rect_pos_, __int8 player_height_);

	static bool RectCollision(Vec player_pos_, Vec rect_pos_, __int8 player_height_, __int8 player_width_, __int8 rect_height_, __int8 rect_width_, EdgeType type);
	
private:
	

	static EdgeInfo m_edge_info[2];
};


#endif