﻿#include "Vec.h"
#ifndef COLLISION_H_
#define COLLISION_H_

/**
*@clss   当たり判定クラス
*/

//!当たり判定時調べる辺
enum EdgeType
{
	TOP,    //!上辺
	BOTTOM,	//!下辺
	LEFT,	//!左辺
	RIGHT	//!右辺
};

//!矩形の各辺
struct EdgeInfo
{
	__int8 top;     //!上辺
	__int8 bottom;	//!下辺
	__int8 left;	//!左辺
	__int8 right;	//!右辺
};

class Collision
{
public:
	Collision() {}
	~Collision() {}

	//!辺と辺の当たり判定
	static bool EdgeCollision(Vec player_pos_, Vec rect_pos_, __int8 player_height_, __int8 player_width_, __int8 rect_height_, __int8 rect_width_, EdgeType type);
	
private:
	//!各辺変数
	static EdgeInfo m_edge_info[2];
};


#endif