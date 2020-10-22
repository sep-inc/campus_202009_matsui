#ifndef PACMAN_PLAYER_
#define PACMAN_PLAYER_
#include "../../Utility/Vec2.h"
#include "../../Definition.h"
#include "../PacManItem.h"
#include "../PacManStage.h"

class PacManPlayer
{
public:
	PacManPlayer() {}
	~PacManPlayer() {}

	/**
　   * @brief  初期化関数
	 * @detail メンバ変数の初期化
　   */
	void Init(PacManStage* stage_, PacManItem* item_);

	/**
　   * @brief  共通外変数初期化関数
	 * @detail 子クラスで初期化の値が違う変数を初期化する
　   */
	virtual void InitAnother() = 0;

	/**
　   * @brief  更新関数
	 * @detail 各更新処理をまとめたもの
　   */
	virtual void Update() = 0;

	/**
　   * @brief  移動方向選択関数
　   */
	virtual void SelectDirection() = 0;

	/**
　   * @brief  描画情報送信関数
	 * @detail 描画に必要な情報をdrawerに渡す
　   */
	void SetUpDrawBuffer();

	/**
   　* @brief  移動関数
	 * @detail 移動方向を移動させる
   　*/
	virtual void Move() = 0;

	/**
　   * @brief  結果表示関数
	 * @detail メンバ変数の初期化
　   */
	void ResultDraw();

	/**
	 * @brief  死亡フラグGetter関数
	 * @detail プレイヤー(EnemyとMyself)が死んだかどうかを返す
	 */
	const bool GetDeth() { return m_deth; }

	/**
	 * @brief  死亡フラグGetter関数
	 * @detail プレイヤー(EnemyとMyself)が死んだかどうかを返す
	 */
	const bool GetClear() { return m_clear; }

protected:
	PacManStage* m_stage;       //!ステージクラスアドレス保存用
	PacManItem* m_item;         //!アイテムクラスのアドレス保存用

	OBJECT_TYPE m_player_type;  //!プレイヤータイプ(自分がだれかが分かるように)

	Vec m_pos;           //!座標
	Vec m_sorce_pos;     //!移動前座標

	Vec m_direction;         //!方向ベクトル

	const char* m_draw_font; //!描画スタイル
	bool m_deth;	         //!死亡フラグ
	bool m_clear;	         //!クリアフラグ

	bool m_wall_hit;         //!壁との当たり判定フラグ
};

#endif