#ifndef SECOND_H_
#define SECOND_H_
#include "../Vec.h"
#include "Piece.h"


/**
 *@clss   駒クラス
 *@brief  プレイヤー、敵の駒情報を持つ
 */
class Second :public Piece
{
public:
	Second() {}
	~Second() {}
	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	virtual void Init()override;

	virtual void InitMove();

	/**
	 * @brief  描画座標代入関数
	 * @detail 駒座標を描画座標に代入
	 */
	virtual void SetUpDrawBuffer()override;

	/**
	 * @brief  先手移動関数
	 * @detail 先手の移動処理
	 */


private:

	
};


#endif