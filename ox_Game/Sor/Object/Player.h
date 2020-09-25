#ifndef PLAYER_H_
#define PLAYER_H_
#include "../Vec.h"
#include "Piece.h"

/**
 *@clss   駒クラス
 *@brief  プレイヤー、敵の駒情報を持つ
 */
class Player :public Piece
{
public:
	Player(){}
	~Player() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Init()override;

	/**
	 * @brief  描画座標代入関数
	 * @detail 駒座標を描画座標に代入
	 */
	virtual void SetUpDrawBuffer()override;

	/**
	 * @brief  移動関数
	 * @detail 駒の移動処理
	 */
	virtual void Put()override;
};


#endif