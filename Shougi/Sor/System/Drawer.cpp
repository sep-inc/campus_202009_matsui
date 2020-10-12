#include "Drawer.h"
#include "../Entity.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>

//!Object描画座標変換関数
void Drawer::SetUpBuffer(Vec2 pos_, const char* font_)
{
	strcpy_s(m_draw_buffer[pos_.y][pos_.x].kind, FONT_BYTE, font_);
}

//!クリア配列代入関数
void Drawer::SetUpClearBuffer(const void* kind_, int size)
{
	memcpy(m_clear_buffer, kind_, size);
}

//!描画関数
void Drawer::Draw()
{
	std::string linking_buffer;  //!文字列連結用

	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			linking_buffer += m_draw_buffer[i][j].kind;  //!文字列連結
		}
		linking_buffer += "\n"; //!改行
	}

	//!描画
	printf("%s", linking_buffer.c_str());
}


//!描画配列クリア関数
void Drawer::Clear()
{
	memcpy(m_draw_buffer, m_clear_buffer, sizeof(m_clear_buffer));  //!移動後の後を消すため

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }); //!左上に描画のカーソルを戻す
}

