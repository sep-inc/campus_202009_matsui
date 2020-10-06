#ifndef PIECE_HU
#define PIECE_HU
#include "Piece.h"
/**
 *@clss   「歩」の駒クラス
 */

#define PAWN_NUM 4  //!歩の数

class PiecePawn :public Piece
{
public:
	PiecePawn();
	~PiecePawn() {}

private:
	//!移動範囲配列
	static const __int8 m_move_[MOVE_MAX_Y][MOVE_MAX_X]; //!先手

};

#endif