#include "SceneBase.h"

//!ステップ処理関数
void SceneBase::Update()
{
	switch (m_step)
	{
	case SceneBase::STEP_INIT:     //!初期化
		Reset();
		break;
	case SceneBase::STEP_UPDATE:   //!更新
		GameControllerUpdate();
		break;
	default:
		break;
	}
}
