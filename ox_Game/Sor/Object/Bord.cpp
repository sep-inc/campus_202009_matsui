#include "Bord.h"
#include "../Entity.h"

//!初期化関数
void Bord::Init()
{
	__int8 number = 1;  //!置ける場所番号を1～9で定義するため

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			m_bord_info[y][x].m_put_number = number;  //!置ける場所番号
			m_bord_info[y][x].m_put_object = 0;       //!何も盤上に置いていないので0初期化

			number++;
		}
	}
}

//!調査関数
bool Bord::Search()
{
	//!勝ち判定
	if (EndSearch(OBJECT_TYPE::PLAYER_PIECE) == true)
	{
		g_drawer.DrawJudgment(WIN);  //!文字表示
		return true;
	}
	//!負け判定
	if(EndSearch(OBJECT_TYPE::ENEMY_PIECE) == true)
	{
		g_drawer.DrawJudgment(LOSE); //!文字表示
		return true;
	}
	//!引き分け判定
	else if (DrawSearch() == true)
	{
		g_drawer.DrawJudgment(DRAW); //!文字表示
		return true;
	}

	return false;
}

//!終了判定(勝敗)関数
bool Bord::EndSearch(__int8 object)
{
	__int8 piece_count_x = 0;  //!横の判定用
	__int8 piece_count_y = 0;  //!縦の判定用


	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			//!横に指定した駒が置いてある場合カウント+1
			if (m_bord_info[y][x].m_put_object == object)
			{
				piece_count_x++;

				//!同じ駒が3つ以上ある場合終了
				if (piece_count_x == 3)
				{
					return true;
				}
			}
			//!縦に指定した駒が置いてある場合カウント+1
			else if (m_bord_info[x][y].m_put_object == object)
			{
				piece_count_y++;

				//!同じ駒が3つ以上ある場合終了
				if (piece_count_y == 3)
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
bool Bord::DrawSearch()
{
	//!盤上に駒がすべて置かれていて、同じ駒が3つ以上そろっていない場合true
	if (SearchNumber() == false && g_bord.EndSearch(OBJECT_TYPE::PLAYER_PIECE) == false
		&& g_bord.EndSearch(OBJECT_TYPE::ENEMY_PIECE) == false)
	{
		return true;
	}
	return false;
}

//!置けるかどうか判定関数
bool Bord::PutSearch(__int8 input_font,__int8 input_number)
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
bool Bord::SearchNumber()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
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
void Bord::SetPiecePos(Vec piece_,__int8 object_)
{
	m_bord_info[piece_.y][piece_.x].m_put_object = object_;
}

