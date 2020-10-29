#ifndef HANOITOWER_OBJECTBASE_H_
#define HANOITOWER_OBJECTBASE_H_
#include "../../../Definition.h"
#include "../../../Utility/Vec2.h"

class ObjectBase
{
public:
	ObjectBase() {}
	~ObjectBase() {}

	virtual void Init(Vec2 pos_, __int8 width, __int8 height);  //初期化

protected:
	Vec2 m_pos;          //初期化
	__int8 m_width;		//横幅
	__int8 m_height;	//縦幅

};

#endif 