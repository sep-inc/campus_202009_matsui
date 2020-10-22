#ifndef PACMAN_ENEMY_H_
#define PACMAN_ENEMY_H_
#include "PacManPlayer.h"
#include "AI/AIBase.h"

#define ENEMY_NUM 3 //!敵の数
#define ENEMY_RANGE_X 5  //!生成間隔範囲のX軸最大値
#define ENEMY_RANGE_Y 5	 //!生成間隔範囲のY軸最大値

#define RANGE_CENTER_X (ENEMY_RANGE_X / 2)	 //!生成間隔範囲のX軸中心値
#define RANGE_CENTER_Y (ENEMY_RANGE_Y / 2)	 //!生成間隔範囲のY軸中心値



class PacManEnemy :public PacManPlayer
{
public:
	PacManEnemy() {}
	~PacManEnemy() {}

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
	 * @detail ランダムで移動方向を決める
　   */
	virtual void SelectDirection()override;

	/**
	* @brief  乱数座標初期化関数
	* @detail 初期座標をランダムで初期化する
	*/
	void RandCreate();

	/**
     * @brief  自分の周り調査関数
     * @detail 自分の検索範囲内に壁以外何があるか調べる
     */
	bool SearchRange(Vec pos_);

	/**
　   * @brief  移動関数
     * @detail 移動方向を移動させる
　   */
	virtual void Move()override;



private:
	AIBase* m_ai_base;

	__int16 m_move_counter;
	__int16 m_move_speed;

	static const __int16 m_move_maxcount;


};

#endif
