#ifndef PIECE_HU
#define PIECE_HU
#include "Piece.h"

class PieceHu :public Piece
{
public:
	PieceHu() {}
	~PieceHu() {}

	bool SearchMove(Vec center_pos_, Vec input_pos_, PLAYER_TYPE player_type_);

private:
	//!移動範囲配列
	static const __int8 m_first_hu_move[MOVE_MAX][MOVE_MAX]; //!先手

	static const __int8 m_second_hu_move[MOVE_MAX][MOVE_MAX]; //!後手
};

#endif