#ifndef TRON_MYSELF_H_
#define TRON_MYSELF_H_
#include "TronPlayer.h"

/**
*@clss   ステージクラス
*@brief  壁(不変的なもの)とプレイヤーの移動跡の情報を持っている
*/

class TornMyself :public TronPlayer
{
public:
	TornMyself() {}
	~TornMyself() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数初期化
	 */
	virtual void Init()override;

	/**
	 * @brief  移動方向選択関数
	 * @detail キー入力で移動方向を選択する
	 */
	virtual void SelectDirection()override;
private:

};

#endif