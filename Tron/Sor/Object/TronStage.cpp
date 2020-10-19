#include "TronStage.h"
#include "../Entity.h"

//!初期化関数
void TronStage::Init()
{
	//!壁(不変的なもの)と空で初期化
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		for (int x = 0; x < GAME_WIDTH; x++)
		{
			m_stage[y][x].m_obj = NONE;  //!空

			//!壁
			m_stage[0][x].m_obj = WALL;
			m_stage[GAME_HEIGHT - 1][x].m_obj = WALL;
			m_stage[y][0].m_obj = WALL;
			m_stage[y][GAME_WIDTH - 1].m_obj = WALL;
		}
	}

	//!ステージが描画情報を送るのは一度だけでいい
	SetUpDrawBuffer();
}

//!描画配列代入関数
void TronStage::SetUpDrawBuffer()
{
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		for (int x = 0; x < GAME_WIDTH; x++)
		{
			//!オブジェクトの種類
			switch (m_stage[y][x].m_obj)
			{
			case WALL: //!壁
				g_drawer.SetUpBuffer(Vec(x, y), "◆");
				break;
			case NONE: //!空
				g_drawer.SetUpBuffer(Vec(x, y), "　");
				break;
			default:
				break;
			}
		}
	}
}

//!ステージ更新関数
void TronStage::SetUpStageBuffer(Vec pos, OBJECT_TYPE type)
{
	m_stage[pos.y][pos.x].m_obj = type;
}

//!指定箇所検索関数
OBJECT_TYPE TronStage::SearchObjectType(Vec pos_)
{
	return m_stage[pos_.y][pos_.x].m_obj;
}
