#ifndef HANOITOWER_DISK_H_
#define HANOITOWER_DISK_H_
#include "HanoiTowerObjectBase.h"
#include "HanoiTowerBoxArray.h"

class Disk :public ObjectBase
{
public:
	Disk() {}
	~Disk() {}

	virtual void Init(Vec2 pos_, unsigned  __int8 width_, unsigned  __int8 height_);  //初期化

	void SetUpBuffer();  //描画座標を代入

	void SetPos(unsigned __int8 number_, unsigned  __int8 width_, HanoiTowerBoxArray* boxarray_);

	Vec2 GetPos() { return m_pos; };
	__int8 GetWidth() { return m_width; };


};

#endif 