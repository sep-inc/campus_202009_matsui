#ifndef HANOITOWER_BOX_H_
#define HANOITOWER_BOX_H_
#include "HanoiTowerObjectBase.h"

class HanoiTowerBox :public ObjectBase
{
public:
	HanoiTowerBox() {}
	~HanoiTowerBox() {}

	virtual void Init(Vec2 pos_, unsigned  __int8 width_, unsigned  __int8 height_);  //初期化

	void SetUpBuffer();  //描画座標を代入
};

#endif 