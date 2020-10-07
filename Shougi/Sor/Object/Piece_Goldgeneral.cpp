#include "Piece_Goldgeneral.h"
#include <string.h>

//!移動範囲配列初期化(0が移動不可,1が移動可)
const __int8 PieceGoldgeneral::m_move_[MOVE_MAX_Y][MOVE_MAX_X] =
{
	0,0,0,
	1,1,1,
	1,2,1,
	0,1,0
};

//!コンストラクタ
PieceGoldgeneral::PieceGoldgeneral()
{
	//!先頭ポインタで初期化
	m_move = m_move_;

	//!描画用文字
	m_first_draw_font = "金";  //!先手
	m_second_draw_font = "筋"; //!後手
}
