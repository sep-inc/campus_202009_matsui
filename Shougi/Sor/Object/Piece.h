#ifndef PIECE_H_
#define PIECE_H_
#include "../Vec.h"
#include "../Definition.h"
///////////////////////////////////////////////////////////////////////////////////////////
//!今後描画やデータの持ち方によって変わってくる可能性があるため、データが少なくても分ける//
///////////////////////////////////////////////////////////////////////////////////////////

#define HU_NUM 4 //!1プレイヤーの持つ歩の数

//!移動範囲配列の基準座標
static const Vec move_center = Vec(1, 1);  //!王と金と歩

class Piece
{
public:
	Piece(){}
	~Piece() {}

	/**
	 * @brief  移動判定
     * @param (center_pos_) 駒の移動範囲配列の基準座標
	 * @param (input_pos_) 移動先の座標
	 * @param (piece_type_) 駒の種類
	 * @param (player_type_) 先手か後手
	 * @detail 先手、後手の選んだ駒が移動できるか判定
	 */
	//bool SearchMove(Vec center_pos_, Vec input_pos_, OBJECT_TYPE piece_type_, PLAYER_TYPE player_type_);

};


#endif