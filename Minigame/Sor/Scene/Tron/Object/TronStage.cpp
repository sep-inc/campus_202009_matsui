#include "TronStage.h"
#include "../../../System/DrawController.h"

//!初期化関数
void TronStage::Reset()
{
	//!壁(不変的なもの)と空で初期化
	for (int y = 0; y < TRON_GAME_HEIGHT; y++)
	{
		for (int x = 0; x < TRON_GAME_WIDTH; x++)
		{
			m_stage[y][x].m_obj = TRON_NONE;  //!空

			//!壁
			m_stage[0][x].m_obj = TRON_WALL;
			m_stage[TRON_GAME_HEIGHT - 1][x].m_obj = TRON_WALL;
			m_stage[y][0].m_obj = TRON_WALL;
			m_stage[y][TRON_GAME_WIDTH - 1].m_obj = TRON_WALL;
		}
	}

	//!ステージが描画情報を送るのは一度だけでいい
	SetUpDrawBuffer();
}

//!描画配列代入関数
void TronStage::SetUpDrawBuffer()
{
	for (int y = 0; y < TRON_GAME_HEIGHT; y++)
	{
		for (int x = 0; x < TRON_GAME_WIDTH; x++)
		{
			//!オブジェクトの種類
			switch (m_stage[y][x].m_obj)
			{
			case TRON_WALL: //!壁
				DrawController::Instance()->SetUpBuffer(Vec2(x, y), "◆");
				break;
			case TRON_NONE: //!空
				DrawController::Instance()->SetUpBuffer(Vec2(x, y), "　");
				break;
			default:
				break;
			}
		}
	}
}

//!ステージ更新関数
void TronStage::SetUpStageBuffer(Vec2 pos, TRON_OBJECT_TYPE type)
{
	m_stage[pos.y][pos.x].m_obj = type;
}

//!指定箇所検索関数
TRON_OBJECT_TYPE TronStage::SearchObjectType(Vec2 pos_)
{
	return m_stage[pos_.y][pos_.x].m_obj;
}
