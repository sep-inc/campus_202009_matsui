#include "HanoiTowerDrawer.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>

HanoiTowerDrawer::HanoiTowerDrawer()
{
	for (int y = HANOITOWER_START_UNIT; y < HANOITOWER_BUFFER_HEIGHT; y++)
	{
		for (int x = HANOITOWER_START_UNIT; x < HANOITOWER_BUFFER_WIDTH; x++)
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


void HanoiTowerDrawer::SetUpClearBuffer(Vec2 pos_, const char* font_)
{
	strcpy_s(m_clear_buffer[pos_.y][pos_.x].kind, FONT_BYTE_, font_);
}

/* 描画関数 */
void HanoiTowerDrawer::Draw()
{
	for (int y = HANOITOWER_START_UNIT; y < HANOITOWER_BUFFER_HEIGHT; y++)
	{
		for (int x = HANOITOWER_START_UNIT; x < HANOITOWER_BUFFER_WIDTH; x++)
		{
			printf("%s", m_draw_buffer[y][x].kind);
		}
		printf("\n");
	}
}

DrawBase* HanoiTowerDrawer::InstanceHanoiTower()
{
	return static_cast<DrawBase*>(new HanoiTowerDrawer);
}
