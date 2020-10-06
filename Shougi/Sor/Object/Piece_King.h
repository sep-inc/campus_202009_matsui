#ifndef PIECE_OU
#define PIECE_OU
#include "Piece.h"
/**
 *@clss   「王」の駒クラス
 */
class PieceKing :public Piece
{
public:
	PieceKing() {}
	~PieceKing() {}

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
	static const __int8 m_ou_move[MOVE_MAX][MOVE_MAX]; //!王だけ先手と後手の動きが同じなため1つにまとめる
};


#endif