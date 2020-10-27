#ifndef PACMAN_PLAYER_
#define PACMAN_PLAYER_
#include "../../../../../Utility/Vec2.h"
#include "../../../../../Definition.h"
#include "../PacManItem.h"
#include "../PacManStage.h"

class PacManPlayer
{
public:
	/**
　   * @brief  コンストラクタ
	 * @param (stage_) ステージのアドレス
　　 * @param (item_) アイテムのアドレス
　　 * @param (player_type_) プレイヤータイプ(自分がだれかが分かるように)
　　 * @param (m_font_) 描画スタイル
　   */
	PacManPlayer(PacManStage* stage_, PacManItem* item_, PACMAN_OBJECT_TYPE player_type_, const char* m_font_);
	virtual ~PacManPlayer() {}

	/**
　   * @brief  初期化関数(繰り返し)
	 * @param (stage_) ステージのアドレス
　　 * @param (item_) アイテムのアドレス
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	void Reset();

	/**
　   * @brief  共通外変数初期化関数
	 * @detail 子クラスで初期化の値が違う変数を初期化する
　   */
	virtual void ResetAnother() = 0;

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

protected:
	PacManStage* m_stage;       //!ステージクラスアドレス保存用
	PacManItem* m_item;         //!アイテムクラスのアドレス保存用

	const PACMAN_OBJECT_TYPE m_player_type;  //!プレイヤータイプ(自分がだれかが分かるように)

	Vec2 m_pos;               //!座標
	Vec2 m_sorce_pos;         //!移動前座標
	Vec2 m_direction;         //!方向ベクトル

	const char* m_draw_font; //!描画スタイル

	//!フラグ情報
	struct FlgInfo
	{
		bool m_deth;	         //!死亡フラグ
		bool m_clear;	         //!クリアフラグ
		bool m_wall_hit;         //!壁との当たり判定フラグ
	};

	FlgInfo m_flg_info;

public:
	/**
	 * @brief  各フラグGetter関数
	 * @detail フラグ構造体の中身を返す
	 */
	const FlgInfo GetFlgInfo() { return m_flg_info; }
};

#endif