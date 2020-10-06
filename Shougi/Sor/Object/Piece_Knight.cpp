#include "Piece_Knight.h"

//!移動範囲配列初期化(0が移動不可,1が移動可)
const __int8 PieceKnight::m_first_kei_move[MOVE_MAX][MOVE_MAX] =
{
	1,0,1,
	0,0,0,
	0,0,0
}; //!桂

const __int8 PieceKnight::m_second_kei_move[MOVE_MAX][MOVE_MAX] =
{
	0,0,0,
	0,0,0,
	1,0,1
}; //!桂

//!置けるかどうか判定関数
bool PieceKnight::SearchMove(Vec center_pos_, Vec input_pos_, PLAYER_TYPE player_type_)
{
	Vec difference_pos;  //!移動先と駒座標の差分保存用
	Vec move_pos;        //!移動先(盤上)座標を移動範囲配列に直した時の座標

	//!移動先と駒座標の差分を出す
	difference_pos = Vec(input_pos_.x - center_pos_.x, input_pos_.y - center_pos_.y);

	//!移動先(盤上)座標を移動範囲配列に直す
	//!桂馬だけ先手と後手で移動範囲の基準座標が違うため分ける
	if (player_type_ == FIRST)
	{
		move_pos = Vec(first_kei_center.x + difference_pos.x, first_kei_center.y + difference_pos.y);
	}
	else
	{
		move_pos = Vec(second_kei_center.x + difference_pos.x, second_kei_center.y + difference_pos.y);
    }
	
	//!移動範囲に入ってない場合
	if ((move_pos.x < MOVE_MIN || move_pos.y < MOVE_MIN) || (move_pos.x >= MOVE_MAX || move_pos.y >= MOVE_MAX))
	{
		return false;
	}

	//!移動範囲に入っている場合
	if (player_type_ == FIRST)
	{
		//!移動範囲に入っているなら
		if (m_first_kei_move[move_pos.y][move_pos.x] == MOVE_POSSIBLE)
		{
			return true;
		}
	}
	else
	{
		//!移動範囲に入っているなら
		if (m_second_kei_move[move_pos.y][move_pos.x] == MOVE_POSSIBLE)
		{
			return true;
		}
	}

	return false;
}
