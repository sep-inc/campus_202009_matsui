#include "HanoiTowerDrawer.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>

HanoiTowerDrawer::HanoiTowerDrawer()
{
	for (int y = START_UNIT; y < BUFFER_HEIGHT; y++)
	{
		for (int x = START_UNIT; x < BUFFER_WIDTH; x++)
		{
			strcpy_s(m_clear_buffer[y][x].kind, FONT_BYTE_, "　");
		}
	}
}


void HanoiTowerDrawer::SetUpBuffer(Vec2 pos_, const char* font_)
{
	strcpy_s(m_draw_buffer[pos_.y][pos_.x].kind, FONT_BYTE_, font_);
}

/* クリア関数*/
void HanoiTowerDrawer::Clear()
{
	//!カーソル座標を左上に
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });

	memcpy(&m_draw_buffer, &m_clear_buffer, sizeof(m_draw_buffer));
}

///* 描画座標変換関数 */
//void HanoiTowerDrawer::SetUpBuffer(Vec2 pos_, __int16 width_, __int16 height_, HANOITOWER_OBJECT_TYPE kind_)
//{
//	__int16 x = static_cast<__int16>(pos_.x);
//	__int16 y = static_cast<__int16>(pos_.y);
//
//	/* 描画に必要な数分回す */
//	for (int x2 = START_UNIT; x2 < width_; x2++)
//	{
//		for (int y2 = START_UNIT; y2 < height_; y2++)
//		{
//			m_draw_buffer[y + y2][x + x2].m_kind = kind_;
//		}
//
//	}
//}

void HanoiTowerDrawer::SetUpClearBuffer(Vec2 pos_, const char* font_)
{
	strcpy_s(m_clear_buffer[pos_.y][pos_.x].kind, FONT_BYTE_, font_);
}

/* 描画関数 */
void HanoiTowerDrawer::Draw()
{
	for (int y = START_UNIT; y < BUFFER_HEIGHT; y++)
	{
		for (int x = START_UNIT; x < BUFFER_WIDTH; x++)
		{
			printf("%s", m_draw_buffer[y][x].kind);
			//if (m_draw_buffer[y][x].m_kind == HANOITOWER_OBJECT_TYPE::BOX)
			//{
			//	printf("□");          //2=箱
			//}
			//else if (m_draw_buffer[y][x].m_kind == HANOITOWER_OBJECT_TYPE::DISK)
			//{
			//	printf("■");          //3=円盤
			//}
			//else
			//{
			//	printf("　");          //0=空白
			//}
		}
		printf("\n");
	}
}
