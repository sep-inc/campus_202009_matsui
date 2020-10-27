#ifndef STOP_AI_H_
#define STOP_AI_H_
#include "AIBase.h"

/**
*@clss   追跡型AIクラス
*@brief  壁越しを除く同じ軸上にプレイヤーを見つけたら速度を上げ追跡するAI
*/

class StopAI :public AIBase
{
public:
	StopAI() {}
	~StopAI() {}

	/**
	　   * @brief  初期化関数
		 * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
	　   */
	virtual void Reset()override;

	/**
　   * @brief  移動方向選択関数
	 * @detail 今回は停止するため方向ベクトルを0で返す
　   */
	virtual Vec2 SelectDirection(Vec2 pos_)override;
};

#endif
