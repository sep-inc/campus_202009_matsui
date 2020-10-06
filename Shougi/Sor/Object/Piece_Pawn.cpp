#include "Piece_Pawn.h"
#include <string.h>

//!移動範囲配列初期化(0が移動不可,1が移動可)
const __int8 PiecePawn::m_move_[MOVE_MAX_Y][MOVE_MAX_X] =
{
	0,0,0,
	0,1,0,
	0,2,0,
	0,0,0
}; 

//!コンストラクタ
PiecePawn::PiecePawn()
{
	memcpy(&m_move, &m_move_, sizeof(m_move_));

	//!描画用文字
	m_first_draw_font = "歩";   //!先手
	m_second_draw_font = "ふ";  //!後手
}
