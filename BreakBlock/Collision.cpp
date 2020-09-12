#include "Collision.h"

/* ��`�Ɖ~�̏㉺�̂����蔻�� */
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

/* ��`�Ɖ~�̍��E�̂����蔻�� */
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

/* Ball����`�Ɏ΂߂�����������p */
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
