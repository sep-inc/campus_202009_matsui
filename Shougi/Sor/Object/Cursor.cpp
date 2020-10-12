#include "Cursor.h"
#include "../Definition.h"
#include "../Entity.h"

//!初期化
void Cursor::Init()
{
	m_pos = Vec2(0, 3);   //!座標
	m_decision = false;   //!決定したかどうかのフラグ
	m_display_timer = 0;        //!表示させる時間
}

//!移動関数
Vec2 Cursor::Move()
{
	g_inputter.InputArrowKey();  //!入力待ち

	//!移動量加算
	m_pos.x += g_inputter.GetNextPos().x;
	m_pos.y += g_inputter.GetNextPos().y;
	
	//!移動範囲判定
	if (m_pos.x < CURSOR_MOVE_MIN) { m_pos.x = CURSOR_MOVE_MIN; }
	else if (m_pos.x > CURSOR_MOVE_MAX_X) { m_pos.x = CURSOR_MOVE_MAX_X; }
	else if (m_pos.y < CURSOR_MOVE_MIN) { m_pos.y = CURSOR_MOVE_MIN; }
	else if (m_pos.y > CURSOR_MOVE_MAX_Y) { m_pos.y = CURSOR_MOVE_MAX_Y; }

	return m_pos;
}

//!指定箇所決定関数
bool Cursor::MoveEnd()
{
	//!決定キーが押されたかどうか
	if (g_inputter.GetDecision() == true)
	{ 
		return true;
	}
	else { return false; }
}

//!描画配列代入関数
void Cursor::SetUpDrawCursor()
{
	//!フレーム分座標を直すよう
	Vec2 pos = m_pos;

	//!フレーム分座標を直す
	pos.x = pos.x * FRAME_X + 1;
	pos.y = pos.y * FRAME_Y + 1;

	m_display_timer++;  //!表示時間加算

	//!表示中
	if (m_display_timer <= DISPLAY_TIME)
	{
		g_drawer.SetUpBuffer(Vec2(pos.x, pos.y - 1), "━ ");
		g_drawer.SetUpBuffer(Vec2(pos.x, pos.y + 1), "━ ");
		g_drawer.SetUpBuffer(Vec2(pos.x - 1, pos.y), "┃ ");
		g_drawer.SetUpBuffer(Vec2(pos.x + 1, pos.y), "┃ ");
	}
	
	//!非表示中
	if (m_display_timer == NONE_DISPLAY_TIME)
	{
		m_display_timer = 0;
	}
	
}
