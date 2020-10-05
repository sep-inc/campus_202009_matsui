#ifndef PIECE_OU
#define PIECE_OU
#include "Piece.h"





class PieceOu :public Piece
{
public:
	PieceOu() {}
	~PieceOu() {}

	bool SearchMove(Vec center_pos_, Vec input_pos_, PLAYER_TYPE player_type_);

private:
	//!移動範囲配列
	static const __int8 m_ou_move[MOVE_MAX][MOVE_MAX]; //!王だけ先手と後手の動きが同じなため1つにまとめる
};


#endif