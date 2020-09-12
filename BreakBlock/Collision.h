#ifndef COLLISION_H_
#define COLLISION_H_
#include "Vec2.h"

/* ��`�Ɖ~�̂����蔻�� */
bool Hit_Rect_TopUnder(Vec2 pos_a_, Vec2 pos_b_, float radius_, float width_, float height_);    //�㉺
bool Hit_Rect_LeftRight(Vec2 pos_a_, Vec2 pos_b_, float radius_, float width_, float height_);   //���E
bool HitVec(Vec2 pos_a_, Vec2 pos_b_, float width_, float height_);

#endif