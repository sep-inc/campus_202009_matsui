#ifndef DRAWER_H_
#define DRAWER_H_
#include "../World.h"
#include "../Vec.h"

#define FRAME_UNIT 1

/* 描画クラス */
class Drawer
{
public:
	Drawer() {}
	~Drawer() {}

	void Init();           //初期化関数
	void Clear();          //クリア関数
	void SetUpBuffer(Vec pos_, __int16 width_, __int16 height_, OBJECT_TYPE kind_);    //オブジェクトセット関数
	void Draw();           //描画関数

private:
	struct Buffer
	{
		OBJECT_TYPE m_kind;
	};

	Buffer m_draw_buffer[BUFFER_HEIGHT][BUFFER_WIDTH];   //描画用配列
	Buffer m_clear_buffer[BUFFER_HEIGHT][BUFFER_WIDTH];   //描画用配列
};


#endif 