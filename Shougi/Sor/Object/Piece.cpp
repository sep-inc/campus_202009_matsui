#include "Piece.h"
#include "../Entity.h"
#include "Piece_Ou.h"
#include "Piece_Keima.h"
#include "Piece_Kin.h"
#include "Piece_Hu.h"
#include <random>

//!置けるかどうか判定関数
//bool Piece::SearchMove(Vec center_pos_, Vec input_pos_,OBJECT_TYPE piece_type_ , PLAYER_TYPE player_type_)
//{
//	Vec difference_pos;  //!移動先と駒座標の差分保存用
//	Vec move_pos;        //!移動先(盤上)座標を移動範囲配列に直した時の座標
//
//	//!移動先と駒座標の差分を出す
//	difference_pos = Vec(input_pos_.x - center_pos_.x, input_pos_.y - center_pos_.y);
//	
//	//!移動先(盤上)座標を移動範囲配列に直す
//	switch (piece_type_)
//	{
//	case OU:   //!王
//		move_pos = Vec(move_center.x + difference_pos.x, move_center.y + difference_pos.y);
//		break;
//	case KEIMA: //!桂
//		//!桂馬だけ先手と後手で移動範囲の基準座標が違うため分ける
//		if (player_type_ == FIRST)
//		{
//			move_pos = Vec(first_kei_center.x + difference_pos.x, first_kei_center.y + difference_pos.y);
//		}
//		else
//			move_pos = Vec(second_kei_center.x + difference_pos.x, second_kei_center.y + difference_pos.y);
//		break;
//	case KIN:  //!金
//		move_pos = Vec(move_center.x + difference_pos.x, move_center.y + difference_pos.y);
//		break;
//	case HU:   //!歩
//		move_pos = Vec(move_center.x + difference_pos.x, move_center.y + difference_pos.y);
//		break;
//	default:
//		break;
//	}
//
//	//!移動範囲に入ってない場合
//	if ((move_pos.x < MOVE_MIN || move_pos.y < MOVE_MIN) || (move_pos.x >= MOVE_MAX || move_pos.y >= MOVE_MAX))
//	{
//		return false;
//	}
//
//	//!移動範囲に入っている場合
//	switch (piece_type_)
//	{
//	case OU:  //!王
//		//!王だけ先手も後手も移動範囲が変わらない
//		if (ou_move[move_pos.y][move_pos.x] == 1)
//		{
//			//!移動範囲に入っているなら
//			return true;
//		}
//	case KEIMA:  //!桂
//		if (player_type_ == FIRST)
//		{
//			//!移動範囲に入っているなら
//			if (first_kei_move[move_pos.y][move_pos.x] == 1)
//			{
//				return true;
//			}
//		}
//		else
//		{
//			//!移動範囲に入っているなら
//			if (second_kei_move[move_pos.y][move_pos.x] == 1)
//			{
//				return true;
//			}
//		}
//	case KIN:  //!金
//		if (player_type_ == FIRST)
//		{
//			//!移動範囲に入っているなら
//			if (first_kin_move[move_pos.y][move_pos.x] == 1)
//			{
//				return true;
//			}
//		}
//		else
//		{
//			//!移動範囲に入っているなら
//			if (second_kin_move[move_pos.y][move_pos.x] == 1)
//			{
//				return true;
//			}
//		}
//	case HU:  //!歩
//		if (player_type_ == FIRST)
//		{
//			//!移動範囲に入っているなら
//			if (first_hu_move[move_pos.y][move_pos.x] == 1)
//			{
//				return true;
//			}
//		}
//		else
//		{
//			//!移動範囲に入っているなら
//			if (second_hu_move[move_pos.y][move_pos.x] == 1)
//			{
//				return true;
//			}
//		}
//	default:
//		break;
//	}
//	
//	return false;
//}





