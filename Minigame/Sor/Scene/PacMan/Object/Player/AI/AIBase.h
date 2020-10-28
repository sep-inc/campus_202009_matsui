#ifndef AI_BASE_H_
#define AI_BASE_H_
#include "../../PacManStage.h"
#include "../../../../../Utility/Vec2.h"
#include "../../../../../Definition.h"
/**
*@clss   AIの基底クラス
*/

class AIBase
{
public:
	AIBase() {}
	~AIBase() {}

	/**
　   * @brief  初期化関数
	 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
	virtual void Reset() = 0;

	/**
　   * @brief  移動方向選択関数
	 * @detail 各AIで求めた移動方向ベクトルを返す
　   */
	virtual Vec2 SelectDirection(Vec2 pos_) = 0;

	bool GetParam_change() { return m_param_change; }

protected:
	PacManStage* m_stage;       //!ステージクラスアドレス保存用

	Vec2 m_direction;      //!方向ベクトル

	bool m_param_change;  //!敵のパラメーター(スピード変更フラグ)
};

#endif