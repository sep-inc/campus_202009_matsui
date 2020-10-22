#ifndef PACMAN_STAGE_H_
#define PACMAN_STAGE_H_
#include "../Utility/Vec2.h"
#include "../Definition.h"


class PacManStage
{
public:
	PacManStage() {}
	~PacManStage() {}

	/**
　   * @brief  初期化関数
	 * @detail メンバ変数の初期化
　   */
	void Init();

	/**
　   * @brief  描画情報送信関数
	 * @detail 描画に必要な情報をdrawerに渡す
　   */
	void SetUpDrawBuffer();

	/**
　   * @brief  ステージ情報更新関数
	 * @detail ステージの情報を他のオブジェクトから座標を受け取り更新する
　   */
	void SetUpStageBuffer(Vec sorce_pos_, Vec pos_, OBJECT_TYPE obje_type_);

	/**
　   * @brief  指定箇所検索関数
	 * @detail 指定された場所に何があるか返す
　   */
	OBJECT_TYPE SearchObject(Vec pos_);

private:
	//!ステージ情報
	struct StageInfo
	{
		OBJECT_TYPE m_obj; //!オブジェクトの種類
	};

	StageInfo m_stage[GAME_HEIGHT][GAME_WIDTH];

};

#endif