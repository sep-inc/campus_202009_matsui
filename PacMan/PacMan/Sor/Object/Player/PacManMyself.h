#ifndef PACMAN_MYSELF_H_
#define PACMAM_MYSELF_H_
#include "PacManPlayer.h"

#define MYSELF_INIT_POS_X 3 //!初期X座標
#define MYSELF_INIT_POS_Y 6	//!初期Y座標

class PacManMyself :public PacManPlayer
{
public:
	PacManMyself() {}
	~PacManMyself() {}

	/**
　   * @brief  共通外変数初期化関数
	 * @detail 子クラスで初期化の値が違う変数を初期化する
　   */
	virtual void InitAnother()override;

	/**
　   * @brief  更新関数
	 * @detail 各更新処理をまとめたもの
　   */
	virtual void Update()override;

	/**
	 * @brief  移動方向選択関数
	 * @detail キー入力で移動方向を選択する
	 */
	virtual void SelectDirection()override;

	/**
　   * @brief  当たり判定関数
	 * @detail 移動先で何に当たったかを調べる
　   */
	void Collision();

	/**
　   * @brief  移動関数
	 * @detail 移動方向を移動させる
　   */
	virtual void Move()override;

private:
	__int8 m_item_counter;
};

#endif