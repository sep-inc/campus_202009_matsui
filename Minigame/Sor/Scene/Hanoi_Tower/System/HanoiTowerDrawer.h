#ifndef HANOITOWER_DRAWER_H_
#define HANOITOWER_DRAWER_H_
#include "../../../Definition.h"
#include "../../../Utility/Vec2.h"
#include "../../../System/DrawBase.h"

#define FRAME_UNIT 1

/* 描画クラス */
class HanoiTowerDrawer :public DrawBase
{
public:
	HanoiTowerDrawer();
	~HanoiTowerDrawer() {}

	//void Init();           //初期化関数

	   /**
	* @brief  Object描画座標変換関数
	* @param (pos_) Objectの座標
	* @param (font_) 表示する形
	* @detail 描画座標にオブジェクト情報代入
	*/
	virtual void SetUpBuffer(Vec2 pos_, const char* font_)override;

	/**
	 * @brief  クリア用配列代入関数
	 * @param (pos_) Objectの座標
	 * @param (font_) 表示する形
	 * @detail クリア用配列に不変的なものだけ代入する
	 */
	virtual void SetUpClearBuffer(Vec2 pos_, const char* font_)override;

	void Clear();          //クリア関数
	//void SetUpBuffer(Vec2 pos_, __int16 width_, __int16 height_, HANOITOWER_OBJECT_TYPE kind_);    //オブジェクトセット関数
	void Draw();           //描画関数

private:
	/*struct Buffer
	{
		HANOITOWER_OBJECT_TYPE m_kind;
	};*/

	struct DrawBuffer
	{
		char kind[4];
	};

	//Buffer m_draw_buffer[BUFFER_HEIGHT][BUFFER_WIDTH];   //描画用配列
	//Buffer m_clear_buffer[BUFFER_HEIGHT][BUFFER_WIDTH];   //描画用配列

	DrawBuffer m_draw_buffer[BUFFER_HEIGHT][BUFFER_WIDTH];  //!描画用配列
	DrawBuffer m_clear_buffer[BUFFER_HEIGHT][BUFFER_WIDTH];  //!描画用配列
};


#endif 