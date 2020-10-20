#ifndef TRON_PLAYER_H_
#define TRON_PLAYER_H_
#include "../../Utility/Vec.h"
#include "../../Definition.h"
#include "../TronStage.h"

/**
*@clss   ステージクラス
*@brief  壁(不変的なもの)とプレイヤーの移動跡の情報を持っている
*/


class TronPlayer
{
public:
	TronPlayer() {}
	~TronPlayer() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数初期化
	 */
	void Init(Vec pos_, TronStage* p_stage_);

	/**
	 * @brief  更新関数
	 * @detail 移動するまでの更新処理
	 */
	void Update();

	/**
	 * @brief  移動関数
	 */
	void Move();

	/**
	 * @brief  移動方向選択関数
	 * @detail 移動方向の決め方はMyselfとEnemyで違う
	 */
	virtual void SelectDirection() = 0;

	/**
	 * @brief  当たり判定関数
	 * @detail ステージクラスに移動先が何かに当たっているか問う
	 */
	bool Collision();

	/**
	 * @brief  描画配列代入関数
	 * @detail プレイヤーの描画情報を描画配列に送る
	 */
	void SetUpDrawBuffer();

	/**
     * @brief  結果表示関数
     * @detail プレイヤーのどちらが勝ったかを表示する
     */
	void ResultDraw();

	/**
	 * @brief  移動フラグGetter関数
	 * @detail プレイヤー(Myself)が移動したかどうかを返す
	 */
	const bool GetMove() { return m_move; }

	/**
	 * @brief  死亡フラグGetter関数
	 * @detail プレイヤー(EnemyとMyself)が死んだかどうかを返す
	 */
	const bool GetDeth() { return m_deth; }


protected:
	TronStage* m_stage;  //!ステージクラスアドレス保存用

	OBJECT_TYPE m_player_type;  //!プレイヤータイプ(自分がだれかが分かるように)

	Vec m_pos;       //!座標
	Vec m_direction; //!方向ベクトル
	const char* m_draw_font; //!描画スタイル
	bool m_deth;	 //!死亡フラグ
	bool m_move;	 //!移動フラグ

};

#endif