#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_
#include "../../PacManStage.h"
#include "ChaseAI.h"
#include "StopAI.h"
#include "AIBase.h"


/**
*@clss   AIの管理クラス
*@brief  各AI(現在は追跡のみ)の移動方向選択処理の継承元を持っている
*/

//!AIの種類
enum AI_TYPE
{
	CHASE,
	STOP,
	AI_NUM
};

class AIController
{
public:
	AIController(PacManStage* stage_);
	~AIController();

	/**
　   * @brief  初期化関数(繰り返し)
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	void Reset();

	/**
　   * @brief  AIパターン更新関数
	 * @param (pos_) Enemyの座標
	 * @detail 時間経過でAIパターンを切り替える
　   */
	void ChangeAI(Vec2 pos_);

	/**
　   * @brief  移動方向Getter
	 * @detail 各AIで選択した移動方向を渡す
　   */
	Vec2 GetDirection() { return m_direction; }

	/**
　   * @brief  追跡判定関数
	 * @detail ChaseAIで追跡中かを判定し、それを返す
　   */
	bool ChaseMode();

	/**
　   * @brief  解放関数
　   */
	void DeleteAI();

protected:
	AIBase* m_ai[AI_NUM]; //!各AI

	Vec2 m_direction;      //!方向ベクトル

	__int16 m_change_counter;   //!AI切り替え時間カウンター

	static const __int16 m_chase_ai_count;	//!ChaseAI中の時間
	static const __int16 m_change_maxcount;	//!StopAIからChaseAIまでの時間

	bool m_chase;  //!追跡フラグ

};

#endif
