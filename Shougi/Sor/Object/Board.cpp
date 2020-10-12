#include "Board.h"
#include "../Entity.h"
#include <string.h>
#include <random>

//!コンストラクタ
Board::Board()
{
	m_winner = NONE;  //!空で初期化
}

//!初期化関数
void Board::Init()
{
	//!不変的なもの
	char m_board_buffer[GAME_HEIGHT][GAME_WIDTH][4];

	//!外枠を除いた枠線を代入
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		for (int x = 0; x < GAME_WIDTH; x++)
		{
			if (y % 2 == 0)
			{
				if (x % 2 == 0)
				{
					strcpy_s(m_board_buffer[y][x], FONT_BYTE, "┼ ");
				}
				else
				{
					strcpy_s(m_board_buffer[y][x], FONT_BYTE, "─ ");
				}
			}
			else
			{
				if (x % 2 == 0)
				{
					strcpy_s(m_board_buffer[y][x], FONT_BYTE, "│ ");
				}
				else
				{
					strcpy_s(m_board_buffer[y][x], FONT_BYTE, "　");
				}
			}

		}
	}
	
	//!x軸方向の外枠線を代入
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		if (y % 2 == 0)
		{
			strcpy_s(m_board_buffer[y][0], FONT_BYTE, "├ ");
			strcpy_s(m_board_buffer[y][GAME_WIDTH - 1], FONT_BYTE, "┤ ");
		}
	}

	//!y軸方向の外枠線を代入
	for (int x = 0; x < GAME_WIDTH; x++)
	{
		if (x % 2 == 0)
		{
			strcpy_s(m_board_buffer[0][x], FONT_BYTE, "┬ ");
			strcpy_s(m_board_buffer[GAME_HEIGHT - 1][x], FONT_BYTE, "┴ ");
		}
	}

	//!上下左右の外枠線を代入
	strcpy_s(m_board_buffer[0][0], FONT_BYTE, "┌ ");
	strcpy_s(m_board_buffer[0][GAME_WIDTH - 1], FONT_BYTE, "┐ ");
	strcpy_s(m_board_buffer[GAME_HEIGHT - 1][0], FONT_BYTE, "└ ");
	strcpy_s(m_board_buffer[GAME_HEIGHT - 1][GAME_WIDTH - 1], FONT_BYTE, "┘ ");

	//!描画配列クリア用に代入
	g_drawer.SetUpClearBuffer(m_board_buffer,sizeof(m_board_buffer));


	//!初期配置コピー用
	BoardInfo map[BORD_HEIGHT][BORD_WIDTH] =
	{
	 //!{駒の種類 , プレイヤー}
		{{GOLDGENERAL, SECOND},{KING,  SECOND},{BLANK, NONE  },{KNIGHT,      SECOND}},
		{{PAWN,        SECOND},{PAWN,  SECOND},{PAWN,  SECOND},{PAWN,        SECOND}},
		{{BLANK,       NONE  },{BLANK, NONE  },{BLANK, NONE  },{BLANK,       NONE  }},
		{{PAWN,        FIRST },{PAWN,  FIRST },{PAWN,  FIRST },{PAWN,        FIRST }},
		{{KNIGHT,      FIRST },{BLANK, NONE  },{KING,  FIRST },{GOLDGENERAL, FIRST }}
	};

	//!配列の初期化は宣言と同時にしかできないためコピーで代入する
	memcpy(&m_board_info, &map, sizeof(map));
	memcpy(&m_board_clear, &map, sizeof(map));
}

//!駒調査関数
PIECE_TYPE Board::SearchPiece(Vec2 pos_)
{
	m_source_pos = pos_;              //!移動させる駒の座標を保存
	return m_board_info[pos_.y][pos_.x].m_put_piece;   //!指定された場所の駒を返す
}

//!プレイヤー調査関数
PLAYER_TYPE Board::SearchPlayer(Vec2 pos_)
{
	return m_board_info[pos_.y][pos_.x].m_put_player;   //!指定された場所の駒を返す
}


//!駒移動関数
void Board::SetPiecePos(Vec2 next_pos, PIECE_TYPE object_, PLAYER_TYPE player_)
{
	//!移動先が「王の場合」終了フラグをtrueにする
	if (m_board_info[next_pos.y][next_pos.x].m_put_piece == KING)
	{
		m_winner = m_board_info[m_source_pos.y][m_source_pos.x].m_put_player; //!勝者を保存
	}

	//!移動元を0にして何もない状態にする
	m_board_info[m_source_pos.y][m_source_pos.x].m_put_piece = BLANK;  
	m_board_info[m_source_pos.y][m_source_pos.x].m_put_player = NONE;

	//!駒を移動させる
	m_board_info[next_pos.y][next_pos.x].m_put_piece = object_;
	m_board_info[next_pos.y][next_pos.x].m_put_player = player_;
}

//!駒座標調査関数
Vec2 Board::SearchPiecePos(PIECE_TYPE object_, PLAYER_TYPE player_,__int8 pawn_number)
{
	for (int y = 0; y < BORD_HEIGHT; y++)
	{
		for (int x = pawn_number; x < BORD_WIDTH; x++)
		{
			if (m_board_info[y][x].m_put_piece == object_ &&
				m_board_info[y][x].m_put_player == player_)
			{
				m_source_pos = Vec2(x, y);  //!移動させる駒の座標を保存
				return Vec2(x, y);          //!座標を返す
			}
		}
	}
	
	//!見つからない場合盤上配列以外の数値を返す
	return Vec2(-1, -1);
}

//!描画配列代入関数
void Board::SetUpDrawBuffer(Piece* piece_[])
{

	for (int y = 0; y < BORD_HEIGHT; y++)
	{
		for (int x = 0; x < BORD_WIDTH; x++)
		{
			//!何か駒が置いてある場合
			if (m_board_info[y][x].m_put_piece != BLANK)
			{
				//!駒にどのような文字で描画するか問う
				piece_[m_board_info[y][x].m_put_piece]->DrawPiece(m_board_info[y][x].m_put_player, Vec2(x, y));
			}
		}
	}
}

//!リセット関数
void Board::Reset()
{
	memcpy(&m_board_info, &m_board_clear, sizeof(m_board_clear));
	m_winner = NONE;
}




