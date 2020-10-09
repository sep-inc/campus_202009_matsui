#include "Drawer.h"
#include "../Entity.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>


//!初期化関数
void Drawer::Init()
{
	//!不変的なもの
	char m_frame_buffer[GAME_HEIGHT][GAME_WIDTH][FONT_BYTE] =
	{
	   "　 "," "  ,"   ",  " ",  "   "," ",  "   "," ","   "," ",
	   " 　","┌ ","─ ","┬ ","─ ","┬ ","─ ","┬ ","─ ","┐ ",
	   "   ","│ ","　", "│ ","　", "│ ","　", "│ ","　", "│ ",
	   " 　","├ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┤ ",
	   "   ","│ ","　", "│ ","　", "│ ","　", "│ ","　", "│ ",
	   " 　","├ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┤ ",
	   "   ","│ ","　", "│ ","　", "│ ","　", "│ ","　", "│ ",
	   " 　","├ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┤ ",
	   "   ","│ ","　", "│ ","　", "│ ","　", "│ ","  ", "│ ",
	   " 　","├ ","─ ","┼ ","─ ","┼ ","─ ","┼ ","─ ","┤ ",
	   "   ","│ ","　", "│ ","　", "│ ","　", "│ ","　", "│ ",
	   " 　","└ ","─ ","┴ ","─ ","┴ ","─ ","┴ ","─ ","┘ ",
	};


	//!描画配列とクリア用配列に代入
	memcpy(&m_draw_buffer, &m_frame_buffer, sizeof(m_frame_buffer));
	memcpy(&m_clear_buffer, &m_frame_buffer, sizeof(m_frame_buffer));
}

//!クリア関数
void Drawer::SetUpBuffer(Vec2 pos_, const char* font_)
{
	strcpy_s(m_draw_buffer[pos_.y][pos_.x].kind, FONT_BYTE, font_);
}

//!描画関数
void Drawer::Draw()
{
	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			printf("%s", m_draw_buffer[i][j].kind);
		}
		printf("\n");
	}
}

void Drawer::SetCursorPos(int x, int y)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}


//!描画配列クリア関数
void Drawer::Clear()
{
	memcpy(m_draw_buffer, m_clear_buffer, sizeof(m_clear_buffer));
	system("cls");
	SetCursorPos(0, 0);

}

