﻿#ifndef PACMAN_STAGE_H_
#define PACMAN_STAGE_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"

class PacManStage
{
public:
	PacManStage();
	~PacManStage() {}

	/**
　   * @brief  初期化関数
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	void Reset();

	/**
　   * @brief  描画情報送信関数
	 * @detail 描画に必要な情報をdrawerに渡す
　   */
	void SetUpDrawBuffer();

	/**
　   * @brief  ステージ情報更新関数
	 * @param (sorce_pos_) 更新前の座標
	 * @param (pos_) 更新後の座標
	 * @param (obje_type_) オブジェクトの種類
	 * @detail ステージの情報を他のオブジェクトから座標を受け取り更新する
　   */
	void SetUpStageBuffer(Vec2 sorce_pos_, Vec2 pos_, PACMAN_OBJECT_TYPE obje_type_);

	/**
　   * @brief  指定箇所検索関数
	 * @param (pos_) 指定座標
	 * @detail 指定された場所に何があるか返す
　   */
	PACMAN_OBJECT_TYPE SearchObject(Vec2 pos_);

private:
	//!ステージ情報
	struct StageInfo
	{
		PACMAN_OBJECT_TYPE m_obj; //!オブジェクトの種類
	};

	StageInfo m_stage[PACMAN_GAME_HEIGHT][PACMAN_GAME_WIDTH];  //!ステージ配列

	static const StageInfo m_stage_copy[PACMAN_GAME_HEIGHT][PACMAN_GAME_WIDTH];   //初期化用ステージ配列

};

#endif