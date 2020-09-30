#include "Bord.h"
#include "../Entity.h"
#include <string.h>


//!初期化関数
void Bord::Init()
{
	memset(m_bord_info, 0, sizeof(m_bord_info));  //!何も盤上に置いていないので0初期化
}

//!調査関数
__int8 Bord::SearchPiece(__int8 input_font_, __int8 input_number_)
{
	return m_bord_info[input_number_][input_font_].m_put_object;
}

//!調査関数
__int8 Bord::SearchPlayer(__int8 input_font_, __int8 input_number_)
{
	return m_bord_info[input_number_][input_font_].m_put_player;
}


//!調査座標代入関数
void Bord::SetPiecePos(Vec piece_, __int8 object_, bool display_, __int8 player_)
{
	if (display_ == true)
	{
		m_bord_info[piece_.y][piece_.x].m_put_object = object_;
		m_bord_info[piece_.y][piece_.x].m_put_player = player_;
	}
}



