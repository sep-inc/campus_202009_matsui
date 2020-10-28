#ifndef TRON_MYSELF_H_
#define TRON_MYSELF_H_
#include "TronPlayer.h"
/**
*@clss   ステージクラス
*@brief  壁(不変的なもの)とプレイヤーの移動跡の情報を持っている
*/

#define MYSELF_INIT_POS_X 2 //!初期X座標
#define MYSELF_INIT_POS_Y 5	//!初期Y座標


class TornMyself :public TronPlayer
{
public:
	TornMyself();
	~TornMyself() {}

	/**
	 * @brief  移動方向選択関数
	 * @detail キー入力で移動方向を選択する
	 */
	virtual void SelectDirection()override;
private:

};

#endif