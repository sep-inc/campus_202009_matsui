#ifndef PIECE_KIN
#define PIECE_KIN
#include "Piece.h"




class PieceKin :public Piece
{
public:
	PieceKin() {}
	~PieceKin() {}

	bool SearchMove(Vec center_pos_, Vec input_pos_, PLAYER_TYPE player_type_);


private:
	//!移動範囲配列
	static const __int8 m_first_kin_move[MOVE_MAX][MOVE_MAX]; //!先手

	static const __int8 m_second_kin_move[MOVE_MAX][MOVE_MAX]; //!後手
};

#endif