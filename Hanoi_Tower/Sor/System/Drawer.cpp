#include "Drawer.h"
#include <stdio.h>
#include <string.h>
#include "../Vec.h"

void Drawer::Init()
{
	memset(&m_clear_buffer, OBJECT_TYPE::BLANK, sizeof(m_clear_buffer));  //クリア用配列初期
	memset(&m_draw_buffer, OBJECT_TYPE::BLANK, sizeof(m_draw_buffer));  //クリア用配列初期


	//memcpy(&m_clear_buffer, &m_draw_buffer, sizeof(m_draw_buffer)); //クリア用配列に壁(不変なObject)をコピー
}

void Drawer::Clear()
{
	memcpy(&m_draw_buffer, &m_clear_buffer, sizeof(m_draw_buffer));
}

void Drawer::SetUpBuffer(Vec pos_,__int16 width_, __int16 height_,OBJECT_TYPE kind_)
{
	__int16 x = static_cast<__int16>(pos_.x);
	__int16 y = static_cast<__int16>(pos_.y);

	/* 描画に必要な数分回す */
	for (int x2 = START_UNIT; x2 < width_; x2++)
	{
		for (int y2 = START_UNIT; y2 < height_; y2++)
		{
			m_draw_buffer[y+ y2][x + x2].m_kind = kind_;
		}
		
	}
}

void Drawer::Draw()
{
	for (int y = START_UNIT; y < BUFFER_HEIGHT; y++)
	{
		for (int x = START_UNIT; x < BUFFER_WIDTH; x++)
		{
			if (m_draw_buffer[y][x].m_kind == OBJECT_TYPE::BOX)
			{
				printf("□");          //2=箱
			}
			else if (m_draw_buffer[y][x].m_kind == OBJECT_TYPE::DISK)
			{
				printf("■");          //3=円盤
			}
			else
			{
				printf("　");          //0=空白
			}
		}
		printf("\n");
	}
}
