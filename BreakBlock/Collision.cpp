#include "Collision.h"

/* 矩形と円の上下のあたり判定 */
bool Hit_Rect_TopUnder(Vec2 pos_a_, Vec2 pos_b_, float radius_, float width_, float height_)
{
	if (pos_a_.X >= pos_b_.X &&
		pos_a_.X <= pos_b_.X + width_ &&
		pos_a_.Y + radius_ >= pos_b_.Y &&
		pos_a_.Y - radius_ <= pos_b_.Y + height_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* 矩形と円の左右のあたり判定 */
bool Hit_Rect_LeftRight(Vec2 pos_a_, Vec2 pos_b_, float radius_, float width_, float height_)
{
	if (pos_a_.X + radius_ >= pos_b_.X &&
		pos_a_.X - radius_ <= pos_b_.X + width_ &&
		pos_a_.Y >= pos_b_.Y &&
		pos_a_.Y <= pos_b_.Y + height_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Ballが矩形に斜めから入った時用 */
bool HitVec(Vec2 pos_a_, Vec2 pos_b_, float width_, float height_)
{
	if (pos_a_.X >= pos_b_.X && 
		pos_a_.X <= pos_b_.X + width_  && 
		pos_a_.Y >= pos_b_.Y && 
		pos_a_.Y <= pos_b_.Y + height_)
	{
		return true;
	}
	else
	{
		return false;
	}
}
