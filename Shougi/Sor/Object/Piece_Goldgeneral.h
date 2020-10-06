#ifndef PIECE_KIN
#define PIECE_KIN
#include "Piece.h"
/**
 *@clss   「金」の駒クラス
 */

class PieceGoldgeneral :public Piece
{
public:
	PieceGoldgeneral() {}
	~PieceGoldgeneral() {}

	/**
	 * @brief  移動判定
	 * @param (center_pos_) 駒の移動範囲配列の基準座標
	 * @param (input_pos_) 移動先の座標
	 * @param (player_type_) 先手か後手
	 * @detail 先手、後手の選んだ駒が移動できるか判定
	 */
	virtual bool SearchMove(Vec center_pos_, Vec input_pos_, PLAYER_TYPE player_type_)override;


private:
	//!移動範囲配列
	static const __int8 m_first_kin_move[MOVE_MAX][MOVE_MAX]; //!先手

	static const __int8 m_second_kin_move[MOVE_MAX][MOVE_MAX]; //!後手
};

#endif