#ifndef TRON_STAGE_H_
#define TRON_STAGE_H_
#include "../Definition.h"
#include "../Utility/Vec.h"

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
	void Init();

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
	void SetUpStageBuffer(Vec pos, OBJECT_TYPE type);

	/**
	 * @brief  指定箇所検索関数
	 * @param (pos_) Object(Player)の座標
	 * @detail ステージ配列の指定座標に何があるか返す
	 */
	OBJECT_TYPE SearchObjectType(Vec pos_);

private:
	//!ステージ情報
	struct StageInfo
	{
		OBJECT_TYPE m_obj; //!オブジェクトの種類
	};

	StageInfo m_stage[GAME_HEIGHT][GAME_WIDTH];

};

#endif