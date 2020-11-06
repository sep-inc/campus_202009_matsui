#include "Drawer.h"
#include "../Entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

Drawer::Drawer()
{
	for (int i = 0; i < DRAW_HEIGHT; i++)
	{
		for (int j = 0; j < DRAW_WIDTH; j++)
		{
			strcpy_s(m_draw_buffer[i][j].kind, FONT_BYTE_, "　");
		}
	}

	memcpy(m_clear_buffer, m_draw_buffer, sizeof(m_draw_buffer));
}

void Drawer::SetUpBuffer(Vec2 pos_, const char* font_, GAME_TYPE type_)
{
	switch (type_)
	{
	case TYPE_A:
		strcpy_s(m_draw_buffer[pos_.y][pos_.x].kind, FONT_BYTE_, font_);
		break;
	case TYPE_B:
		strcpy_s(m_draw_buffer[pos_.y][pos_.x + GAME_WIDTH + 10].kind, FONT_BYTE_, font_);
		break;
	default:
		break;
	}
}

//! クリア用配列代入関数
void Drawer::SetUpClearBuffer(Vec2 pos_, const char* font_)
{
	memcpy(m_draw_buffer, m_clear_buffer, sizeof(m_clear_buffer));
}

//!描画関数
void Drawer::Draw()
{
	std::string linking;  //!文字連結用

	for (int i = 0; i < DRAW_HEIGHT; i++)
	{
		for (int j = 0; j < DRAW_WIDTH; j++)
		{
			linking += m_draw_buffer[i][j].kind;
		}

		linking += "\n";
	}

	printf("%s", linking.c_str());  //!表示
}

//!描画配列クリア関数
void Drawer::Clear()
{
	//!カーソル座標を左上に
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });

	//!不変的なものでクリア
	memcpy(m_draw_buffer, m_clear_buffer, sizeof(m_clear_buffer));
}

