#include "SyougiBoard.h"
#include "../../../System/DrawController.h"
#include <string.h>
#include <random>

//!コンストラクタ
SyougiBoard::SyougiBoard()
{
	m_winner = SYOUGI_NONE;  //!空で初期化

	//!不変的なもの
	char m_board_buffer[SYOUGI_GAME_HEIGHT][SYOUGI_GAME_WIDTH][4];

	//!外枠を除いた枠線を代入
	for (int y = 0; y < SYOUGI_GAME_HEIGHT; y++)
	{
		for (int x = 0; x < SYOUGI_GAME_WIDTH; x++)
		{
			if (y % 2 == 0)
			{
				if (x % 2 == 0)
				{
					strcpy_s(m_board_buffer[y][x], FONT_BYTE_, "┼ ");
				}
				else
				{
					strcpy_s(m_board_buffer[y][x], FONT_BYTE_, "─ ");
				}
			}
			else
			{
				if (x % 2 == 0)
				{
					strcpy_s(m_board_buffer[y][x], FONT_BYTE_, "│ ");
				}
				else
				{
					strcpy_s(m_board_buffer[y][x], FONT_BYTE_, "　");
				}
			}

		}
	}

	//!x軸方向の外枠線を代入
	for (int y = 0; y < SYOUGI_GAME_HEIGHT; y++)
	{
		if (y % 2 == 0)
		{
			strcpy_s(m_board_buffer[y][0], FONT_BYTE_, "├ ");
			strcpy_s(m_board_buffer[y][SYOUGI_GAME_WIDTH - 1], FONT_BYTE_, "┤ ");
		}
	}

	//!y軸方向の外枠線を代入
	for (int x = 0; x < SYOUGI_GAME_WIDTH; x++)
	{
		if (x % 2 == 0)
		{
			strcpy_s(m_board_buffer[0][x], FONT_BYTE_, "┬ ");
			strcpy_s(m_board_buffer[SYOUGI_GAME_HEIGHT - 1][x], FONT_BYTE_, "┴ ");
		}
	}

	//!上下左右の外枠線を代入
	strcpy_s(m_board_buffer[0][0], FONT_BYTE_, "┌ ");
	strcpy_s(m_board_buffer[0][SYOUGI_GAME_WIDTH - 1], FONT_BYTE_, "┐ ");
	strcpy_s(m_board_buffer[SYOUGI_GAME_HEIGHT - 1][0], FONT_BYTE_, "└ ");
	strcpy_s(m_board_buffer[SYOUGI_GAME_HEIGHT - 1][SYOUGI_GAME_WIDTH - 1], FONT_BYTE_, "┘ ");

	//!描画配列クリア用に代入
	for (int y = 0; y < SYOUGI_GAME_HEIGHT; y++)
	{
		for (int x = 0; x < SYOUGI_GAME_WIDTH; x++)
		{
			DrawController::Instance()->SetUpClearBuffer(Vec2(x, y), m_board_buffer[y][x]);
		}
	}

	//!初期配置コピー用
	BoardInfo map[BORD_HEIGHT][BORD_WIDTH] =
	{
		//!{駒の種類 , プレイヤー}
		   {{GOLDGENERAL, SYOUGI_SECOND},{KING,  SYOUGI_SECOND},{BLANK, SYOUGI_NONE  },{KNIGHT,      SYOUGI_SECOND}},
		   {{PAWN,        SYOUGI_SECOND},{PAWN,  SYOUGI_SECOND},{PAWN,  SYOUGI_SECOND},{PAWN,        SYOUGI_SECOND}},
		   {{BLANK,       SYOUGI_NONE  },{BLANK, SYOUGI_NONE  },{BLANK, SYOUGI_NONE  },{BLANK,       SYOUGI_NONE  }},
		   {{PAWN,        SYOUGI_FIRST },{PAWN,  SYOUGI_FIRST },{PAWN,  SYOUGI_FIRST },{PAWN,        SYOUGI_FIRST }},
		   {{KNIGHT,      SYOUGI_FIRST },{BLANK, SYOUGI_NONE  },{KING,  SYOUGI_FIRST },{GOLDGENERAL, SYOUGI_FIRST }}
	};

	//!配列の初期化は宣言と同時にしかできないためコピーで代入する
	memcpy(&m_board_info, &map, sizeof(map));
	memcpy(&m_board_clear, &map, sizeof(map));
}

//!リセット関数
void SyougiBoard::Reset()
{
	memcpy(&m_board_info, &m_board_clear, sizeof(m_board_clear));
	m_winner = SYOUGI_NONE;
}


//!駒調査関数
PIECE_TYPE SyougiBoard::SearchPiece(Vec2 pos_)
{
	m_source_pos = pos_;              //!移動させる駒の座標を保存
	return m_board_info[pos_.y][pos_.x].m_put_piece;   //!指定された場所の駒を返す
}

//!プレイヤー調査関数
SYOUGI_PLAYER_TYPE SyougiBoard::SearchPlayer(Vec2 pos_)
{
	return m_board_info[pos_.y][pos_.x].m_put_player;   //!指定された場所の駒を返す
}


//!駒移動関数
void SyougiBoard::SetPiecePos(Vec2 next_pos, PIECE_TYPE object_, SYOUGI_PLAYER_TYPE player_)
{
	//!移動先が「王の場合」終了フラグをtrueにする
	if (m_board_info[next_pos.y][next_pos.x].m_put_piece == KING)
	{
		m_winner = m_board_info[m_source_pos.y][m_source_pos.x].m_put_player; //!勝者を保存
	}

	//!移動元を0にして何もない状態にする
	m_board_info[m_source_pos.y][m_source_pos.x].m_put_piece = BLANK;
	m_board_info[m_source_pos.y][m_source_pos.x].m_put_player = SYOUGI_NONE;

	//!駒を移動させる
	m_board_info[next_pos.y][next_pos.x].m_put_piece = object_;
	m_board_info[next_pos.y][next_pos.x].m_put_player = player_;
}

//!駒座標調査関数
Vec2 SyougiBoard::SearchPiecePos(PIECE_TYPE object_, SYOUGI_PLAYER_TYPE player_, __int8 pawn_number)
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
void SyougiBoard::SetUpDrawBuffer(SyougiPiece* piece_[])
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





