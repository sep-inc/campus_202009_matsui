﻿#include "RunGameDrawer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

//!クリア関数
void RunGameDrawer::SetUpBuffer(Vec2 pos_, const char* font_)
{
	strcpy_s(m_draw_buffer[pos_.y][pos_.x].kind, FONT_BYTE_, font_);
}

//!クリア配列代入関数
void RunGameDrawer::SetUpClearBuffer(Vec2 pos_, const char* font_)
{
	strcpy_s(m_clear_buffer[pos_.y][pos_.x].kind, FONT_BYTE_, font_);
}

//!描画関数
void RunGameDrawer::Draw()
{
	std::string linking;  //!文字連結用

	for (int i = 0; i < RUNGAME_HEIGHT; i++)
	{
		for (int j = 0; j < RUNGAME_WIDTH - 1; j++)
		{
			linking += m_draw_buffer[i][j].kind;  //!文字連結
		}
		linking += "\n";
	}

	printf("%s", linking.c_str());  //!表示
}

//!描画配列クリア関数
void RunGameDrawer::Clear()
{
	//!クリア用配列で描画配列をクリア
	memcpy(&m_draw_buffer, &m_clear_buffer, sizeof(m_clear_buffer));

	//!カーソル座標を左上に
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
}
