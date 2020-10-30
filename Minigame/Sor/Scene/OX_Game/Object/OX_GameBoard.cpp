#include "OX_GameBoard.h"
#include "../../../System/DrawController.h"

//!初期化関数
void OX_GameBoard::Init()
{
	__int8 number = 1;  //!置ける場所番号を1～9で定義するため

	for (int y = 0; y < BORD_SIZE; y++)
	{
		for (int x = 0; x < BORD_SIZE; x++)
		{
			m_bord_info[y][x].m_put_number = number;  //!置ける場所番号
			m_bord_info[y][x].m_put_object = 0;       //!何も盤上に置いていないので0初期化

			number++;
		}
	}

	m_win = false;
	m_lose = false;
	m_draw = false;

}

//!調査関数
bool OX_GameBoard::Judgment()
{
	//!勝ち判定
	if (EndSearch(OX_GAME_OBJECT_TYPE::OX_GAME_PLAYER_PIECE) == true)
	{
		m_win = true;
		return true;
	}
	//!負け判定
	if (EndSearch(OX_GAME_OBJECT_TYPE::OX_GAME_ENEMY_PIECE) == true)
	{
		m_lose = true;
		return true;
	}
	//!引き分け判定
	else if (JudgmentDraw() == true)
	{
		m_draw = true;
		return true;
	}

	return false;
}

//!終了判定(勝敗)関数
bool OX_GameBoard::EndSearch(__int8 object)
{
	__int8 piece_count_x = 0;  //!横の判定用
	__int8 piece_count_y = 0;  //!縦の判定用


	for (int y = 0; y < BORD_SIZE; y++)
	{
		for (int x = 0; x < BORD_SIZE; x++)
		{
			//!横に指定した駒が置いてある場合カウント+1
			if (m_bord_info[y][x].m_put_object == object)
			{
				piece_count_x++;

				//!同じ駒が3つ以上ある場合終了
				if (piece_count_x == BORD_SIZE)
				{
					return true;
				}
			}
			//!縦に指定した駒が置いてある場合カウント+1
			if (m_bord_info[x][y].m_put_object == object)
			{
				piece_count_y++;

				//!同じ駒が3つ以上ある場合終了
				if (piece_count_y == BORD_SIZE)
				{
					return true;
				}
			}
		}
		piece_count_x = 0;
		piece_count_y = 0;
	}

	//!右下方向の斜めの判定
	if (m_bord_info[0][0].m_put_object == object &&
		m_bord_info[1][1].m_put_object == object &&
		m_bord_info[2][2].m_put_object == object)
	{
		return true;
	}
	//!左下方向の斜めの判定
	else if (m_bord_info[0][2].m_put_object == object &&
		m_bord_info[1][1].m_put_object == object &&
		m_bord_info[2][0].m_put_object == object)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//!終了判定(引き分け)関数
bool OX_GameBoard::JudgmentDraw()
{
	//!盤上に駒がすべて置かれていて、同じ駒が3つ以上そろっていない場合true
	if (SearchNumber() == false && EndSearch(OX_GAME_OBJECT_TYPE::OX_GAME_PLAYER_PIECE) == false
		&& EndSearch(OX_GAME_OBJECT_TYPE::OX_GAME_ENEMY_PIECE) == false)
	{
		return true;
	}
	return false;
}

//!置けるかどうか判定関数
bool OX_GameBoard::PutSearch(__int8 input_font, __int8 input_number)
{
	//!指定した位置に駒がない場合は0
	if (m_bord_info[input_number][input_font].m_put_number > 0)
	{
		//!駒を置いた場所には-1に変えて次のフレーム以降は置けないようにする
		m_bord_info[input_number][input_font].m_put_number = -1;

		return true;
	}

	return false;

}

//!配置場所調査関数
bool OX_GameBoard::SearchNumber()
{
	for (int y = 0; y < BORD_SIZE; y++)
	{
		for (int x = 0; x < BORD_SIZE; x++)
		{
			//!置ける場所があるのか調べる
			if (m_bord_info[y][x].m_put_number >= 0)
			{
				return true;
			}
		}
	}

	return false;
}

//!調査座標代入関数
void OX_GameBoard::SetPiecePos(Vec2 piece_, __int8 object_)
{
	m_bord_info[piece_.y][piece_.x].m_put_object = object_;
}

void OX_GameBoard::DrawResult()
{
	if (m_win == true)
	{
		printf("あなたの勝ちです。\n");
	}
	else if (m_lose == true)
	{
		printf("あなたの負けです。\n");
	}
	else if(m_draw == true)
	{
		printf("引き分けです。\n");
	}

}

