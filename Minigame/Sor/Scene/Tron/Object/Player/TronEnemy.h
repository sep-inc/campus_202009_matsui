#ifndef TRON_ENEMY_H_
#define TRON_ENEMY_H_
#include "TronPlayer.h"
/**
*@clss   敵クラス
*@brief  移動方向をランダムで決め動く
*/

#define ENEMY_INIT_POS_X 16 //!初期X座標
#define ENEMY_INIT_POS_Y 5	//!初期Y座標

class TronEnemy :public TronPlayer
{
public:
	TronEnemy();
	~TronEnemy() {}

	/**
	 * @brief  移動方向選択関数
	 * @detail 移動方向をランダムで選択する
	 */
	virtual void SelectDirection()override;

	/**
	 * @brief  移動方向検索関数
	 * @detail 移動先が一度も選択されていない方向かどうか
	 */
	bool SearchDirection();


private:
	DIRECTION_TYPE m_rand_direction;
	__int8 m_direction_array[DIRECTION_MAX];
	__int8 m_none_array[DIRECTION_MAX];

};

#endif