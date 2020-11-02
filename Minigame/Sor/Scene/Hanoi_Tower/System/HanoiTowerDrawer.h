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

	/**
	 * @brief  描画配列クリア関数
	 */
	void Clear();          //クリア関数
	
	/**
	 * @brief  描画関数
	 * @detail 描画
	 */
	void Draw();           //描画関数

	/**
	 * @brief  インスタンス返還関数
	 * @detail 管理クラスのポインタ配列に返す
	 */
	static DrawBase* InstanceHanoiTower();

private:
	struct DrawBuffer
	{
		char kind[4];
	};

	DrawBuffer m_draw_buffer[HANOITOWER_BUFFER_HEIGHT][HANOITOWER_BUFFER_WIDTH];   //!描画用配列
	DrawBuffer m_clear_buffer[HANOITOWER_BUFFER_HEIGHT][HANOITOWER_BUFFER_WIDTH];  //!クリア用配列
};


#endif 