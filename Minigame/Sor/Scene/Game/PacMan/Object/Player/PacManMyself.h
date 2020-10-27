#ifndef PACMAN_MYSELF_H_
#define PACMAM_MYSELF_H_
#include "PacManPlayer.h"

#define MYSELF_INIT_POS_X 3 //!初期X座標
#define MYSELF_INIT_POS_Y 6	//!初期Y座標

class PacManMyself :public PacManPlayer
{
public:
	/**
　   * @brief  コンストラクタ
	 * @param (stage_) ステージのアドレス
　　 * @param (item_) アイテムのアドレス
　   */
	PacManMyself(PacManStage* stage_, PacManItem* item_);
	~PacManMyself() {}

	/**
　   * @brief  共通外変数初期化関数
	 * @detail 子クラスで初期化の値が違う変数を初期化する
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	virtual void ResetAnother()override;

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
	__int8 m_item_counter;   //!アイテム取得数
	__int16 m_iput_timer;	 //!入力間隔時間

	static const __int16 m_move_possible;  //!移動可能時間

};

#endif