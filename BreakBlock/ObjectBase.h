#ifndef OBJECTBASE_H_
#define OBJECTBASE_H_
#include "Vec2.h"
#include <vector>
#include  "World.h"


class ObjectBase
{
protected:
	ObjectBase() :m_pos(Vec2(Start_Pos_X, Start_Pos_Y)), m_speed(0.0f), m_eneable(true)
	{}
	~ObjectBase() {}

	virtual void Init(Vec2 pos_, float speed_,bool eneable_);
	virtual void Update() {};
	virtual void Draw() {};

	Vec2 m_pos;
	float m_speed;
	bool m_eneable;

public:
	Vec2 GetPos() { return m_pos; }
};


#endif