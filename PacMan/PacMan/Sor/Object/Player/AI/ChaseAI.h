﻿#ifndef CHASE_AI_H_
#define CHASE_AI_H_
#include "AIBase.h"
/**
*@clss   追跡型AIクラス
*@brief  壁越しを除く同じ軸上にプレイヤーを見つけたら速度を上げ追跡するAI
*/

class ChaseAI :public AIBase
{
public:
	ChaseAI(PacManStage* stage_);
	~ChaseAI() {}

	/**
　   * @brief  初期化関数
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	virtual void Reset()override;

	/**
　   * @brief  プレイヤー捜索関数
	 * @param (pos_) Enemyの座標
	 * @detail 壁越しを除く同じ軸上にプレイヤーがいるかどうか調べる
　   */
	bool SearchPlayer(Vec pos_);

	/**
　   * @brief  移動方向選択関数
	 * @param (pos_) Enemyの座標
	 * @detail ランダムで移動方向を決める
　   */
	virtual Vec SelectDirection(Vec pos_)override;

	/**
　   * @brief  ランダム方向選択関数
	 * @param (pos_) Enemyの座標
	 * @detail 追跡以外の場合に行う
	 * @detail ランダムで移動方向を決める
　   */
	Vec RandDirection(Vec pos_);
	

	/**
	 * @brief  壁当たり判定関数
	 * @param (pos_) Enemyの座標
	 * @param (direction_) 方向ベクトル
	 * @detail 移動先が壁に当たっているかどうか
	 */
	bool CollisionWall(Vec pos_, Vec direction_);

	/**
	 * @brief  移動方向検索関数
	 * @detail 後退以外の方向が選ばれているかどうか
	 */
	bool SearchDirection();

	/**
     * @brief  後退方向更新関数
	 * @param (pos_) Enemyの座標
     * @detail 移動方向を更新した際後退の方向も更新する
     */
	void SetDirection(Vec vec_);

private:
	DIRECTION_TYPE m_rand_direction;          //!選択用移動方向ベクトル
	__int16 m_direction_array[DIRECTION_MAX];  //!移動可能方向配列

	
};

#endif
