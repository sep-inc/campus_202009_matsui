#include "Drawer.h"
#include <stdio.h>
#include <string.h>

//!初期化関数
void Drawer::Init()
{
	char m_frame_buffer[GAME_HEIGHT][GAME_WIDTH][BYTE]=
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
void Drawer::SetUpBuffer(Vec pos_ ,const char* font_)
{
	Vec pos = pos_;

	pos.x = pos.x * 2 + 2;
	pos.y = pos.y * 2 + 2;

	strcpy_s(m_draw_buffer[pos.y][pos.x].kind, BYTE, font_);
}

//!描画関数
void Drawer::Draw()
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

void Drawer::DrawJudgment(JUDGMENT_TYPE type_)
{
	switch (type_)
	{
	case WIN:
		printf("あなたの勝ちです。");
		break;
	case LOSE:
		printf("あなたの負けです。");
		break;
	case DRAW:
		printf("引き分けです。");
		break;
	default:
		break;
	}
	
}
