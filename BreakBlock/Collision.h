#ifndef COLLISION_H_
#define COLLISION_H_
#include "Vec2.h"

/* ãÈå`Ç∆â~ÇÃÇ†ÇΩÇËîªíË */
bool Hit_Rect_TopUnder(Vec2 pos_a_, Vec2 pos_b_, float radius_, float width_, float height_);    //è„â∫
bool Hit_Rect_LeftRight(Vec2 pos_a_, Vec2 pos_b_, float radius_, float width_, float height_);   //ç∂âE
bool HitVec(Vec2 pos_a_, Vec2 pos_b_, float width_, float height_);

#endif