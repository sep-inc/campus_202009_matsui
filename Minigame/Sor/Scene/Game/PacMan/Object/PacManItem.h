#ifndef PACMAN_ITEM_H_
#define PACMAN_ITEM_H_
#include "../../../../Utility/Vec2.h"
#include "../Object/PacManStage.h"

#define ITEM_RANGE_X 5  //!生成間隔範囲のX軸最大値
#define ITEM_RANGE_Y 5	//!生成間隔範囲のY軸最大値

#define ITEM_RANGE_CENTER_X (ITEM_RANGE_X / 2)	 //!生成間隔範囲のX軸中心値
#define ITEM_RANGE_CENTER_Y (ITEM_RANGE_Y / 2)	 //!生成間隔範囲のY軸中心値


class PacManItem
{
public:
	PacManItem(PacManStage* stage_);
	~PacManItem() {}

	/**
　   * @brief  初期化関数
	 * @param (stage_) ステージのアドレス
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	void Reset();

	/**
　   * @brief  更新関数
	 * @detail 各更新処理をまとめたもの
　   */
	void Update();

	/**
　   * @brief  ランダム生成関数
	 * @detail アイテムの初期座標をランダムで決める
　   */
	void RandCreate();

	/**
　   * @brief  生成間隔検索関数
	 * @param (pos_) アイテムの座標
	 * @detail アイテムの生成範囲の中に他のアイテム、またプレイヤーがあるかどうか
　   */
	bool SearchRange(Vec2 pos_);

	/**
　   * @brief  描画情報送信関数
	 * @detail 描画に必要な情報をdrawerに渡す
　   */
	void SetUpDrawBuffer();

	/**
　   * @brief  アイテム消去関数
	 * @param (pos_) アイテムの座標
	 * @detail プレイヤーがアイテムを取った場合そこに合ったアイテムを消す関数
　   */
	void SetLostItem(Vec2 pos_);

private:
	PacManStage* m_stage;  //!ステージクラスアドレス保存用

	//!アイテム情報
	struct ItemInfo
	{
		ItemInfo() :
			m_pos(Vec2(0, 0)), //!座標
			m_exists(false),  //!存在フラグ初期化
			m_draw_font("　") //!描画スタイル
		{}

		Vec2 m_pos;               //!座標
		bool m_exists;           //!存在フラグ
		const char* m_draw_font; //!描画スタイル
	};

	ItemInfo m_item_info[ITEM_NUM];

};

#endif
