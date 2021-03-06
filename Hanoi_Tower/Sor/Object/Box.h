#ifndef BOX_H_
#define BOX_H_
#include "ObjectBase.h"

class Box :public ObjectBase
{
public:
	Box() {}
	~Box() {}

	virtual void Init(Vec pos_, unsigned  __int8 width_, unsigned  __int8 height_);  //初期化
	
	void SetUpBuffer();  //描画座標を代入
};

#endif 