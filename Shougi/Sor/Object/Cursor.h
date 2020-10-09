#ifndef CURSOR_H_
#define CURSOR_H_
#include "../Vec.h"
#include "../Definition.h"
/**
 *@clss   カーソルクラス
 */

#define CURSOR_MOVE_MAX_X 3     //!カーソルの動ける最大範囲
#define CURSOR_MOVE_MAX_Y 4     //!カーソルの動ける最大範囲

#define CURSOR_MOVE_MIN 0     //!カーソルの動ける最小範囲


class Cursor
{
public:
	Cursor();
	~Cursor() {}

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

	bool m_decision;  //!決定したかどうかのフラグ
};
#endif