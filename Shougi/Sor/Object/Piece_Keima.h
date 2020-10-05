#ifndef PIECE_KEIMA
#define PIECE_KEIMA
#include "Piece.h"



//!桂馬
static const Vec first_kei_center = Vec(1, 2);
static const Vec second_kei_center = Vec(1, 0);

class PieceKeima :public Piece
{
public:
	PieceKeima() {}
	~PieceKeima() {}

	bool SearchMove(Vec center_pos_, Vec input_pos_, PLAYER_TYPE player_type_);


private:
	//!移動範囲配列
	static const __int8 m_first_kei_move[MOVE_MAX][MOVE_MAX]; //!先手

	static const __int8 m_second_kei_move[MOVE_MAX][MOVE_MAX]; //!後手
};

#endif