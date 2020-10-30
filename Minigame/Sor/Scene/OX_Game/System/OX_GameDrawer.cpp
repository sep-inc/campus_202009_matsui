#include "OX_GameDrawer.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>


OX_GameDrawer::OX_GameDrawer()
{
	char m_frame_buffer[GAME_HEIGHT][GAME_WIDTH][FONT_BYTE_] =
	{
	   "　 "," ", " A "," ", " B "," ", " C ", "　",
	   " 　","┏ ","━ ","┳ ","━ ","┳ ","━ ","┓ ",
	   " 1 ","┃ ","　", "┃ ","　", "┃ ","　", "┃ ",
	   " 　","┣ ","━ ","╋ ","━ ","╋ ","━ ","┫ ",
	   " 2 ","┃ ","　", "┃ ","　", "┃ ","　", "┃ ",
	   " 　","┣ ","━ ","╋ ","━ ","╋ ","━ ","┫ ",
	   " 3 ","┃ ","　", "┃ ","　", "┃ ","　", "┃ ",
	   " 　","┗ ","━ ","┻ ","━ ","┻ ","━ ","┛ ",
	};

	memcpy(&m_draw_buffer, &m_frame_buffer, sizeof(m_frame_buffer));
	memcpy(&m_clear_buffer, &m_frame_buffer, sizeof(m_frame_buffer));
}

//!クリア関数
void OX_GameDrawer::SetUpBuffer(Vec2 pos_, const char* font_)
{
	Vec2 pos = pos_;

	pos.x = pos.x * 2 + 2;
	pos.y = pos.y * 2 + 2;

	strcpy_s(m_draw_buffer[pos.y][pos.x].kind, FONT_BYTE_, font_);
}

//!描画関数
void OX_GameDrawer::Draw()
{
	for (int i = 0; i < GAME_WIDTH; i++)
	{
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			printf("%s", m_draw_buffer[i][j].kind);
		}
		printf("\n");
	}
}

void OX_GameDrawer::Clear()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }); //!左上に描画のカーソルを戻す
}

DrawBase* OX_GameDrawer::InstanceOX_Game()
{
	return static_cast<DrawBase*>(new OX_GameDrawer);
}

