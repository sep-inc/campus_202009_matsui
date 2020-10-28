#include "TronDrawer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

//!クリア関数
void TronDrawer::SetUpBuffer(Vec2 pos_, const char* font_)
{
	strcpy_s(m_draw_buffer[pos_.y][pos_.x].kind, FONT_BYTE_, font_);
}

//!描画関数
void TronDrawer::Draw()
{
	//!カーソル座標を左上に
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });

	std::string linking;  //!文字連結用

	for (int i = 0; i < TRON_GAME_HEIGHT; i++)
	{
		for (int j = 0; j < TRON_GAME_WIDTH; j++)
		{
			linking += m_draw_buffer[i][j].kind;  //!文字連結
		}
		linking += "\n";
	}

	printf("%s", linking.c_str());  //!表示
}

