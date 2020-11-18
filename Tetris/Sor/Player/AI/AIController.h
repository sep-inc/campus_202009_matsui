#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_
#include "AIBase.h"

/**
*@clss   AIの管理クラス
*@brief  各AI(現在は追跡のみ)の移動方向選択処理の継承元を持っている
*/

//!AIの種類
enum AI_TYPE
{
	MATSUI,
	HUKUDA,
	AI_NUM
};

/////////////////////////////////////////////////////////////////////////////////
//!各敵で色々なAIを組み込むために、現在のAI管理クラスでAIを切り替えるのではなく//
//!敵で切り替えることで簡単に呼び出せる。                                      //
/////////////////////////////////////////////////////////////////////////////////


class Tetris_AIController
{
public:
	Tetris_AIController();
	~Tetris_AIController();

	/**
　   * @brief  初期化関数(繰り返し)
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	void Reset();

	/**
　   * @brief  移動方向Getter
	 * @detail 各AIで選択した移動方向を渡す
　   */
	Vec2 GetDirection() { return m_direction; }

	/**
　   * @brief  追跡判定関数
	 * @detail ChaseAIで追跡中かを判定し、それを返す
　   */
	bool DecisionFlg();

	/**
　   * @brief  解放関数
　   */
	void DeleteAI();

protected:
	Tetris_AIBase* m_ai; //!各AI

	Vec2 m_direction;      //!方向ベクトル
};

#endif
