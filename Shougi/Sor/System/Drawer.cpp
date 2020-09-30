#include "Drawer.h"
#include "../Entity.h"
#include <stdio.h>
#include <string.h>

//!初期化関数
void Drawer::Init()
{
	char m_frame_buffer[GAME_HEIGHT][GAME_WIDTH][BYTE] =
	{
	   "　 "," "  ," A ",  " ",  " B "," ",  " C "," "," D "," ",
	   " 　","┏ ","━ ","┳ ","━ ","┳ ","━ ","┳ ","━ ","┓ ",
	   " 1 ","┃ ","　", "┃ ","　", "┃ ","　", "┃ ","　", "┃ ",
	   " 　","┣ ","━ ","╋ ","━ ","╋ ","━ ","╋ ","━ ","┫ ",
	   " 2 ","┃ ","　", "┃ ","　", "┃ ","　", "┃ ","　", "┃ ",
	   " 　","┣ ","━ ","╋ ","━ ","╋ ","━ ","╋ ","━ ","┫ ",
	   " 3 ","┃ ","　", "┃ ","　", "┃ ","　", "┃ ","　", "┃ ",
	   "   ","┣ ","━ ","╋ ","━ ","╋ ","━ ","╋ ","━ ","┫ ",
	   " 4 ","┃ ","　", "┃ ","　", "┃ ","　", "┃ ","  ", "┃ ",
	   "   ","┣ ","━ ","╋ ","━ ","╋ ","━ ","╋ ","━ ","┫ ",
	   " 5 ","┃ ","　", "┃ ","　", "┃ ","　", "┃ ","　", "┃ ",
	   " 　","┗ ","━ ","┻ ","━ ","┻ ","━ ","┻ ","━ ","┛ ",
	};

	memcpy(&m_draw_buffer, &m_frame_buffer, sizeof(m_frame_buffer));
	memcpy(&m_clear_buffer, &m_frame_buffer, sizeof(m_frame_buffer));
}

//!クリア関数
void Drawer::SetUpBuffer(Vec pos_, const char* font_, bool display_)
{
	if (display_ == true)
	{
		Vec pos = pos_;

		pos.x = pos.x * 2 + 2;
		pos.y = pos.y * 2 + 2;

		strcpy_s(m_draw_buffer[pos.y][pos.x].kind, BYTE, font_);
	}
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

//!動かそうとしている駒表示関数
void Drawer::NowMovePiece(__int8 piece_type_,__int8 player_type_)
{
	switch (piece_type_)
	{
	case OU:
		if (player_type_ == FIRST_PLAYER)   //!先手の場合
		{
			printf("現在動かそうとしているのは王です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは玉です。\n");
		}
		break;
	case KEIMA:
		if (player_type_ == FIRST_PLAYER)  //!先手の場合
		{
			printf("現在動かそうとしているのは桂です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは軽です。\n");
		}
		break;
	case KIN:
		if (player_type_ == FIRST_PLAYER)  //!先手の場合
		{
			printf("現在動かそうとしているのは金です。\n");
		}
		else
		{
			printf("現在動かそうとしているのは筋です。\n");
		}
		break;
	case HU:
		if (player_type_ == FIRST_PLAYER)  //!先手の場合
		{
			printf("現在動かそうとしているのは歩です。\n");
		}
		else
		{
			printf("現在動かそうとしているのはふです。\n");
		}
		break;
	default:
		break;
	}
}

void Drawer::DrawJudgment()
{
	if (g_piece.GetFirstWin() == true)
	{
		printf("先手の勝ちです。\n");
	}
	else if(g_piece.GetSecondWin() == true)
	{
		printf("後手の勝ちです。\n");
	}
}

void Drawer::DrawNoMove()
{
	printf("移動させることができませんでした。\n");
	printf("配置権が移ります。\n");

}

void Drawer::Clear()
{
	memcpy(m_draw_buffer, m_clear_buffer, sizeof(m_clear_buffer));
}
