﻿#include "Piece_Ou.h"

//!移動範囲配列初期化
const __int8 PieceOu::m_ou_move[MOVE_MAX][MOVE_MAX] =
{
	1,1,1,
	1,0,1,
	1,1,1
};  //!王

//!置けるかどうか判定関数
bool PieceOu::SearchMove(Vec center_pos_, Vec input_pos_,PLAYER_TYPE player_type_)
{
	Vec difference_pos;  //!移動先と駒座標の差分保存用
	Vec move_pos;        //!移動先(盤上)座標を移動範囲配列に直した時の座標

	//!移動先と駒座標の差分を出す
	difference_pos = Vec(input_pos_.x - center_pos_.x, input_pos_.y - center_pos_.y);

	//!移動先(盤上)座標を移動範囲配列に直す
	move_pos = Vec(move_center.x + difference_pos.x, move_center.y + difference_pos.y);

	//!移動範囲に入ってない場合
	if ((move_pos.x < MOVE_MIN || move_pos.y < MOVE_MIN) || (move_pos.x >= MOVE_MAX || move_pos.y >= MOVE_MAX))
	{
		return false;
	}

	//!移動範囲に入っている場合
	//!王だけ先手も後手も移動範囲が変わらない
	if (m_ou_move[move_pos.y][move_pos.x] == 1)
	{
		//!移動範囲に入っているなら
		return true;
	}

	return false;
}
