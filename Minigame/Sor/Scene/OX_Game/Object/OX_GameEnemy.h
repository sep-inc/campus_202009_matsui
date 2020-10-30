#ifndef OX_GAME_ENEMY_H_
#define OX_GAME_ENEMY_H_
#include "../../../Utility/Vec2.h"
#include "OX_GameBoard.h"

/**
 *@clss   駒クラス
 *@brief  プレイヤー、敵の駒情報を持つ
 */
class OX_GameEnemy
{
public:
	OX_GameEnemy() {}
	~OX_GameEnemy() {}
	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  描画座標代入関数
	 * @detail 駒座標を描画座標に代入
	 */
	void SetUpDrawBuffer();

	/**
	 * @brief  移動関数
	 * @detail 駒の移動処理
	 */
	void Put(OX_GameBoard* board_);
private:
	Vec2 m_pos;
	Vec2 m_randm_number;   //!敵の配置座標
};


#endif