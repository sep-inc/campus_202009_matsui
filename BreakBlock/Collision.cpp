#include "Collision.h"

/* ‹éŒ`‚Æ‰~‚Ìã‰º‚Ì‚ ‚½‚è”»’è */
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

/* ‹éŒ`‚Æ‰~‚Ì¶‰E‚Ì‚ ‚½‚è”»’è */
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

