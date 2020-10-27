#include "GameControllerBase.h"
#include "../../System/Inputter.h"

//!ステップ処理関数
void GameControllerBase::Update()
{
	switch (m_step)
	{
	case GameControllerBase::STEP_INIT:     //!初期化
		Init();
		break;
	case GameControllerBase::STEP_START:    //!開始待ち
		//!スタートキーが入力されたら
		DrawRule();
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case GameControllerBase::STEP_UPDATE:   //!更新
		ObjectUpdate();
		break;
	case GameControllerBase::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}

