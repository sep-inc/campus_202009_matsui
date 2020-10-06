#ifndef PIECE_H_
#define PIECE_H_
#include "../Vec.h"
#include "../Definition.h"
/**
 *@clss   駒の基底クラス
 */

///////////////////////////////////////////////////////////////////////////////////////////
//!今後描画やデータの持ち方によって変わってくる可能性があるため、データが少なくても分ける//
///////////////////////////////////////////////////////////////////////////////////////////

#define MOVE_POSSIBLE 1 //!移動可能数値

//!移動範囲配列の基準座標
static const Vec move_center = Vec(1, 1);  //!王と金と歩は共通

class Piece
{
public:
	Piece(){}
	~Piece() {}

	/**
	 * @brief  移動判定
     * @param (center_pos_) 駒の移動範囲配列の基準座標
	 * @param (input_pos_) 移動先の座標
	 * @param (player_type_) 先手か後手
	 * @detail 先手、後手の選んだ駒が移動できるか判定
	 */
	virtual bool SearchMove(Vec center_pos_, Vec input_pos_, PLAYER_TYPE player_type_) = 0;
};


#endif