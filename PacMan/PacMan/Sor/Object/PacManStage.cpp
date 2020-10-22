#include "PacManStage.h"
#include "../Entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

//!初期化関数
void PacManStage::Init()
{
	OBJECT_TYPE m_stage_copy[GAME_HEIGHT][GAME_WIDTH] =
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

	memcpy(m_stage, m_stage_copy, sizeof(m_stage_copy));
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
				g_drawer.SetUpClearBuffer(Vec(x, y), "■");
				break;
			case NONE:
				g_drawer.SetUpClearBuffer(Vec(x, y), "　");
				break;
			default:
				break;
			}

		}
	}
}

//!ステージ情報更新関数
void PacManStage::SetUpStageBuffer(Vec sorce_pos_,Vec pos_, OBJECT_TYPE obje_type_)
{
	m_stage[sorce_pos_.y][sorce_pos_.x].m_obj = NONE;

	m_stage[pos_.y][pos_.x].m_obj = obje_type_;
}

//!ステージ検索関数
OBJECT_TYPE PacManStage::SearchObject(Vec pos_)
{
	return m_stage[pos_.y][pos_.x].m_obj;
}
