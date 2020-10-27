#include "PacManStage.h"
#include "../../../../System/DrawController.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

//!不変的なもの(初期ステージ状態)
const PacManStage::StageInfo PacManStage::m_stage_copy[GAME_HEIGHT][GAME_WIDTH] =
{
	WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,
	WALL,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,WALL,
	WALL,NONE,WALL,WALL,WALL,WALL,WALL,NONE,WALL,WALL,WALL,NONE,WALL,
	WALL,NONE,WALL,NONE,NONE,NONE,NONE,NONE,NONE,NONE,WALL,NONE,WALL,
	WALL,NONE,WALL,NONE,WALL,WALL,NONE,WALL,WALL,NONE,NONE,NONE,WALL,
	WALL,NONE,WALL,NONE,WALL,NONE,NONE,NONE,WALL,NONE,WALL,NONE,WALL,
	WALL,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,WALL,NONE,WALL,
	WALL,NONE,WALL,NONE,WALL,NONE,NONE,NONE,WALL,NONE,WALL,NONE,WALL,
	WALL,NONE,WALL,NONE,WALL,WALL,NONE,WALL,WALL,NONE,NONE,NONE,WALL,
	WALL,NONE,WALL,NONE,NONE,NONE,NONE,NONE,NONE,NONE,WALL,NONE,WALL,
	WALL,NONE,WALL,WALL,WALL,NONE,WALL,WALL,WALL,WALL,WALL,NONE,WALL,
	WALL,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,WALL,
	WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,
};

//!コンストラクタ
PacManStage::PacManStage()
{
	memcpy(m_stage, m_stage_copy, sizeof(m_stage_copy));  //!不変的なもので初期化
}

//!初期化関数
void PacManStage::Reset()
{
	memcpy(m_stage, m_stage_copy, sizeof(m_stage_copy));  //!不変的なもので初期化
}

//!描画情報送信関数
void PacManStage::SetUpDrawBuffer()
{
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		for (int x = 0; x < GAME_WIDTH; x++)
		{
			switch (m_stage[y][x].m_obj)
			{
			case WALL:
				DrawController::Instance()->SetUpClearBuffer(Vec2(x, y), "■");
				break;
			case NONE:
				DrawController::Instance()->SetUpClearBuffer(Vec2(x, y), "　");
				break;
			default:
				break;
			}

		}
	}
}

//!ステージ情報更新関数
void PacManStage::SetUpStageBuffer(Vec2 sorce_pos_, Vec2 pos_, PACMAN_OBJECT_TYPE obje_type_)
{
	m_stage[sorce_pos_.y][sorce_pos_.x].m_obj = NONE;   //!移動前座標を空にする

	m_stage[pos_.y][pos_.x].m_obj = obje_type_;   //!移動先を更新
}

//!ステージ検索関数
PACMAN_OBJECT_TYPE PacManStage::SearchObject(Vec2 pos_)
{
	return m_stage[pos_.y][pos_.x].m_obj;
}
