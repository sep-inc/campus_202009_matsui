#ifndef TRON_STAGE_H_
#define TRON_STAGE_H_
#include "../../../Definition.h"
#include "../../../Utility/Vec2.h"

/**
*@clss   ステージクラス
*@brief  壁(不変的なもの)とプレイヤーの移動跡の情報を持っている
*/

class TronStage
{
public:
	TronStage() {}
	~TronStage() {}

	/**
	 * @brief  初期化関数
	 * @detail メンバ変数初期化
	 */
	void Reset();

	/**
	 * @brief  描画配列代入関数
	 * @detail 描画配列に描画情報を送る
	 */
	void SetUpDrawBuffer();

	/**
	 * @brief  ステージ更新関数
	 * @param (pos_) Object(Player)の座標
	 * @param (type_) Object(Player)の種類
	 * @detail ステージの情報をプレイヤーの移動後に更新する
	 */
	void SetUpStageBuffer(Vec2 pos, TRON_OBJECT_TYPE type);

	/**
	 * @brief  指定箇所検索関数
	 * @param (pos_) Object(Player)の座標
	 * @detail ステージ配列の指定座標に何があるか返す
	 */
	TRON_OBJECT_TYPE SearchObjectType(Vec2 pos_);

private:
	//!ステージ情報
	struct StageInfo
	{
		TRON_OBJECT_TYPE m_obj; //!オブジェクトの種類
	};

	StageInfo m_stage[TRON_GAME_HEIGHT][TRON_GAME_WIDTH];

};

#endif