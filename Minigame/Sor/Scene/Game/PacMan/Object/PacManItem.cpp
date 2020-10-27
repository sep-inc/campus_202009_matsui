#include "PacManItem.h"
#include "../../../../System/DrawController.h"

#include <stdlib.h>

//!コンストラクタ
PacManItem::PacManItem(PacManStage* stage_) :
	m_stage(stage_) //!ステージアドレス取得
{
	//!描画スタイル初期化
	m_item_info[0].m_draw_font = "１";
	m_item_info[1].m_draw_font = "２";
	m_item_info[2].m_draw_font = "３";
	m_item_info[3].m_draw_font = "４";
	m_item_info[4].m_draw_font = "５";

}

//!初期化関数
void PacManItem::Reset()
{
	//!存在フラグ初期化
	for (int i = 0; i < ITEM_NUM; i++)
	{
		m_item_info[i].m_exists = true;
	}

	RandCreate();  //!座標初期化
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
		//!生成座標が見つかるまで回す
		while (true)
		{
			m_item_info[i].m_pos.x = rand() % GAME_WIDTH;
			m_item_info[i].m_pos.y = rand() % GAME_HEIGHT;

			//!指定座標が壁であるかどうか
			if (m_stage->SearchObject(m_item_info[i].m_pos) != WALL)
			{
				//!生成間隔範囲内に何もない場合
				if (SearchRange(m_item_info[i].m_pos) == false)
				{
					//!ステージに情報を送る
					m_stage->SetUpStageBuffer(m_item_info[i].m_pos, m_item_info[i].m_pos, ITEM);
					break;
				}
			}
		}
	}
}

//!生成間隔検索関数
bool PacManItem::SearchRange(Vec2 pos_)
{
	Vec2 range;   //!範囲検索座標

	for (int y = 0; y < ITEM_RANGE_Y; y++)
	{
		for (int x = 0; x < ITEM_RANGE_X; x++)
		{
			range.x = pos_.x - ITEM_RANGE_CENTER_X + x;
			range.y = pos_.y - ITEM_RANGE_CENTER_Y + y;

			//!座標がステージの範囲内である場合
			if (range.x > 0 && range.x < GAME_WIDTH &&
				range.y > 0 && range.y < GAME_HEIGHT)
			{
				//!範囲内に何かある場合
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
		//!存在している場合
		if (m_item_info[i].m_exists == true)
		{
			DrawController::Instance()->SetUpBuffer(m_item_info[i].m_pos, m_item_info[i].m_draw_font);
			//PacManDrawer::Instance()->SetUpBuffer(m_item_info[i].m_pos, m_item_info[i].m_draw_font);
			//g_drawer.SetUpBuffer(m_item_info[i].m_pos, m_item_info[i].m_draw_font);
		}
	}
}

//!アイテム消去関数
void PacManItem::SetLostItem(Vec2 pos_)
{
	for (int i = 0; i < ITEM_NUM; i++)
	{
		//!プレイヤーがとったアイテムの座標と重なる要素のアイテム
		if (m_item_info[i].m_pos.x == pos_.x &&
			m_item_info[i].m_pos.y == pos_.y)
		{
			m_item_info[i].m_exists = false;
		}
	}

}
