#ifndef TRON_ENEMY_H_
#define TRON_ENEMY_H_
#include "TronPlayer.h"

/**
*@clss   敵クラス
*@brief  移動方向をランダムで決め動く
*/

//!移動方向の種類
enum DIRECTION_TYPE
{
	UP,                //!上
	DOWN,			   //!下
	LEFT,			   //!左
	RIGHT,			   //!右
	DIRECTION_MAX,	   //!方向の数
	DIRECTION_NONE,	   //!無し
};

class TronEnemy :public TronPlayer
{
public:
	TronEnemy() {}
	~TronEnemy() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数初期化
	 */
	virtual void Init()override;

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