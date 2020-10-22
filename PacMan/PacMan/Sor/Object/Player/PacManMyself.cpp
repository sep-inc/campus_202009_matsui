#include "PacManMyself.h"
#include "../../Entity.h"

//!共通外変数初期化関数
void PacManMyself::InitAnother()
{
	m_player_type = MYSELF;   //!自分のオブジェクトタイプ
	m_draw_font = "●";       //!描画文字

	m_pos = Vec(MYSELF_INIT_POS_X, MYSELF_INIT_POS_Y);   //!座標
	m_sorce_pos = m_pos;      //!移動前座標
	m_item_counter = 0;       //!アイテム取得数
}

//!更新処理
void PacManMyself::Update()
{
	//!移動方向選択
	SelectDirection();

	//!移動
	Move();

	//!ステージ情報更新
	m_stage->SetUpStageBuffer(m_sorce_pos, m_pos, m_player_type);
}

//!移動方向選択関数
void PacManMyself::SelectDirection()
{
	m_sorce_pos = m_pos;  //!移動前座標更新

	m_direction = g_inputter.InpuMoveKey();   //!十字キー入力

	Collision();  //!当たり判定

	//!壁にに当たっている場合
	if (m_wall_hit == true)
	{
		m_direction = Vec(0, 0);  //!方向ベクトルを0にする
		m_wall_hit = false;
	}
}

//!当たり判定関数
void PacManMyself::Collision()
{
	Vec pos = m_pos;   //!移動先座標保存用

	pos.x += m_direction.x;
	pos.y += m_direction.y;

	//!移動先で壁にぶつかっている場合
	if (m_stage->SearchObject(pos) == WALL)
	{
		m_wall_hit = true;
	} 
	//!移動先でアイテムにぶつかっている場合
	else if (m_stage->SearchObject(pos) == ITEM)
	{
		m_item->SetLostItem(pos);  //!どこのアイテムに当たったかを知らせる
		m_item_counter++;          //!取得アイテム数加算

		//!全てのアイテムを集めた場合
		if (m_item_counter == ITEM_NUM)
		{
			system("cls");   //!現在の表示文字を消す
			m_clear = true;  //!クリアフラグtrue
		}
	}
	//!移動先で敵にぶつかっている場合
	else if (m_stage->SearchObject(pos) == ENEMY)
	{
		m_deth = true;   //!死亡フラグtrue
	}
}

//!移動関数
void PacManMyself::Move()
{
	m_pos.x += m_direction.x;
	m_pos.y += m_direction.y;
}
