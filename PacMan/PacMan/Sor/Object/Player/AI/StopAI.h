#ifndef STOP_AI_H_
#define STOP_AI_H_
#include "../../../Utility/Vec2.h"
#include "../../../Definition.h"
#include "../../PacManStage.h"
/**
*@clss   追跡型AIクラス
*@brief  壁越しを除く同じ軸上にプレイヤーを見つけたら速度を上げ追跡するAI
*/

class StopAI
{
public:
	StopAI();
	~StopAI() {}

	/**
　   * @brief  移動方向選択関数
	 * @detail 今回は停止するため方向ベクトルを0で返す
　   */
	Vec SelectDirection();

private:
	Vec m_direction;  //!方向ベクトル

};

#endif
