#ifndef SYOUGI_CURSOR_H_
#define SYOUGI_CURSOR_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"

/**
 *@clss   カーソルクラス
 */

#define CURSOR_MOVE_MAX_X 3     //!カーソルの動ける最大範囲
#define CURSOR_MOVE_MAX_Y 4     //!カーソルの動ける最大範囲

#define CURSOR_MOVE_MIN 0     //!カーソルの動ける最小範囲

#define DISPLAY_TIME 30
#define NONE_DISPLAY_TIME 60


class SyougiCursor
{
public:
	SyougiCursor() {}
	~SyougiCursor() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Reset();

	/**
	 * @brief  移動関数
	 * @detail カーソル移動
	 * @return 移動量を返す
	 */
	Vec2 Move();

	/**
	 * @brief  指定箇所決定関数
	 * @return 移動元、または移動先が決まったかどうか
	 */
	bool MoveEnd();

	/**
　　 * @brief  描画配列代入関数
　　 * @detail 描画配列にカーソルの情報を送る
　　 */
	void SetUpDrawCursor();

protected:
	Vec2 m_pos;  //!カーソルの座標
	Vec2 m_move;  //!移動量


	bool m_decision;  //!決定したかどうかのフラグ

	__int8 m_display_timer; //!表示させる時間
};
#endif