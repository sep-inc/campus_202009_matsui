#include "PacManItem.h"
#include "../Entity.h"
#include <stdlib.h>

//!初期化関数
void PacManItem::Init(PacManStage* stage_)
{
	m_stage = stage_;  //!ステージアドレス取得

	//!存在フラグ初期化
	for (int i = 0; i < ITEM_NUM; i++)
	{
		m_item_info[i].m_exists = true;
	}

	//!描画スタイル初期化
	m_item_info[0].m_draw_font = "１";
	m_item_info[1].m_draw_font = "２";
	m_item_info[2].m_draw_font = "３";
	m_item_info[3].m_draw_font = "４";
	m_item_info[4].m_draw_font = "５";

	RandCreate();
}

//!更新処理
void PacManItem::Update()
{	
	for (int i = 0; i < ITEM_NUM; i++)
	{
		//!存在している場合
		if (m_item_info[i].m_exists == true)
		{
			m_stage->SetUpStageBuffer(m_item_info[i].m_pos, m_item_info[i].m_pos, ITEM);
		}
	}
}

//!更新関数
void PacManItem::RandCreate()
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		while (true)
		{
			m_item_info[i].m_pos.x = rand() % GAME_WIDTH;
			m_item_info[i].m_pos.y = rand() % GAME_HEIGHT;

			if (m_stage->SearchObject(m_item_info[i].m_pos) != WALL)
			{
				if (SearchRange(m_item_info[i].m_pos) == false)
				{
					m_stage->SetUpStageBuffer(m_item_info[i].m_pos, m_item_info[i].m_pos, ITEM);
					break;
				}
			}
		}
	}
}


bool PacManItem::SearchRange(Vec pos_)
{
	Vec range;

	for (int y = 0; y < ITEM_RANGE_Y; y++)
	{
		for (int x = 0; x < ITEM_RANGE_X; x++)
		{
			range.x = pos_.x - 2 + x;
			range.y = pos_.y - 2 + y;

			if (range.x > 0 && range.x < GAME_WIDTH &&
				range.y > 0 && range.y < GAME_HEIGHT)
			{
				if (m_stage->SearchObject(range) != WALL &&
					m_stage->SearchObject(range) != NONE)
				{
					return true;
				}
			}
		}
	}

	return false;
}

//!描画情報送信関数
void PacManItem::SetUpDrawBuffer()
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (m_item_info[i].m_exists == true)
		{
			g_drawer.SetUpBuffer(m_item_info[i].m_pos, m_item_info[i].m_draw_font);	
		}
	}
}

void PacManItem::SetLostItem(Vec pos_)
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (m_item_info[i].m_pos.x == pos_.x &&
			m_item_info[i].m_pos.y == pos_.y)
		{
			m_item_info[i].m_exists = false;
		}
	}
	
}
