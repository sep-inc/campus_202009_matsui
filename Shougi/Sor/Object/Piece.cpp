﻿#include "Piece.h"
#include "../Entity.h"

const Vec2 Piece::move_center = Vec2(1, 2);  //!基準座標初期化

bool Piece::SearchMove(Vec2 center_pos_, Vec2 input_pos_, PLAYER_TYPE player_type_)
{
	Vec2 difference_pos;  //!移動先と駒座標の差分保存用
	Vec2 move_pos;        //!移動先(盤上)座標を移動範囲配列に直した時の座標

	//!移動先と駒座標の差分を出す
	difference_pos = Vec2(input_pos_.x - center_pos_.x, input_pos_.y - center_pos_.y);

	//!移動先(盤上)座標を移動範囲配列に直す
	move_pos = Vec2(move_center.x + difference_pos.x, move_center.y + difference_pos.y);

	//!後手の場合
	if (player_type_ == SECOND)
	{
		//!逆向きに直す
		move_pos = Vec2(move_center.x - difference_pos.x, move_center.y - difference_pos.y);
	}

	//!移動範囲に入ってない場合
	if ((move_pos.x < MOVE_MIN || move_pos.y < MOVE_MIN) || (move_pos.x >= MOVE_MAX_X || move_pos.y >= MOVE_MAX_Y))
	{
		return false;
	}

	//!移動範囲に入っているなら
	if (m_move[move_pos.y][move_pos.x] == MOVE_POSSIBLE)
	{
		return true;
	}

	return false;

	
}

//!駒表示判別関数
void Piece::DrawPiece(PLAYER_TYPE player_type_, Vec2 pos_)
{
	pos_.x = pos_.x * FRAME_X + 1;
	pos_.y = pos_.y * FRAME_Y + 1;

	//!先手の場合
	if (player_type_ == FIRST)
	{
		g_drawer.SetUpBuffer(pos_, m_first_draw_font);
	}
	//!後手の場合
	else if(player_type_ == SECOND)
	{
		g_drawer.SetUpBuffer(pos_, m_second_draw_font);
	}
}

