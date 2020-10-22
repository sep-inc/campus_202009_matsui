#ifndef AI_BASE_H_
#define AI_BASE_H_
#include "../../PacManStage.h"
/**
*@clss   AIの基底クラスクラス
*@brief  各AI(現在は追跡のみ)の移動方向選択処理の継承元を持っている
*/

class AIBase
{
public:
	AIBase() {}
	~AIBase() {}

	/**
　   * @brief  移動方向選択関数
　   */
	virtual Vec SelectDirection(Vec pos_) = 0;

	/**
　   * @brief  追跡フラグGetter
　   */
	bool GetChase() { return m_chase; }

protected:
	PacManStage* m_stage;       //!ステージクラスアドレス保存用

	bool m_chase;  //!追跡フラグ
};

#endif
