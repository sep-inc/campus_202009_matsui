#include "HanoiTowerBox.h"
#include "../../../System/DrawController.h"

/* 初期化 */
void HanoiTowerBox::Init(Vec2 pos_, unsigned  __int8 width_, unsigned  __int8 height_)
{
	ObjectBase::Init(pos_, width_, height_);
}

/* 描画座標を代入 */
void HanoiTowerBox::SetUpBuffer()
{
	//Vec2 pos = m_pos;
	/* 描画に必要な数分回す */
	for (int x2 = START_UNIT; x2 < m_width; x2++)
	{
		for (int y2 = START_UNIT; y2 < m_height; y2++)
		{
			DrawController::Instance()->SetUpBuffer(Vec2(m_pos.x + x2, m_pos.y + y2), "□");
			//m_draw_buffer[m_pos.y + y2][m_pos.x + x2].m_kind = kind_;
		}

	}
	//g_drawer.SetUpBuffer(m_pos, m_width, m_height, HANOITOWER_OBJECT_TYPE::BOX);
}
