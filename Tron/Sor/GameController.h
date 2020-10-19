﻿#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_
#include "Object/Player/TronPlayer.h"
#include "Definition.h"


class GameController
{
public:
	GameController();
	~GameController();


	/**
	 * @brief  初期化関数
	 * @detail メンバ変数の初期化
	 */
	void Init();

	/**
	 * @brief  ステップ処理関数
	 * @detail ステップ変更処理
	 */
	void Update();

	/**
   　* @brief  更新関数
	 * @detail 各更新処理をまとめた関数
   　*/
	void ObjectUpdate();

	/**
	 * @brief  描画情報代入関数
	 * @detail 盤情報を描画配列に代入
	 */
	void SetUpDrawBuffer();

	/**
	 * @brief  勝敗判定関数
	 * @detail 先手か後手のどちらが勝ったかを判定する
	 */
	void GameResult();

	/**
	 * @brief  強制終了関数
	 * @detail ESCが押されたときにゲームを終了する
	 */
	bool GameEnd();

	/**
	 * @brief 解放処理関数
	 */
	void Delete();

	//!各オブジェクトのアドレスのGetter
	TronStage* GetStagePoint() { return m_stage; }

private:
	//!ステップの種類
	enum STEP
	{
		STEP_INIT,    //!初期化
		STEP_START,   //!初期化
		STEP_UPDATE,  //!更新
		STEP_RESULT,  //!結果
	}m_step;

	TronPlayer* m_player[PLAYER_MAX];  //!プレイヤー
	TronStage* m_stage;        //!マップ


};


#endif