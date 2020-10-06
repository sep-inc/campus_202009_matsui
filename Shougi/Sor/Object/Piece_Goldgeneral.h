#ifndef PIECE_KIN
#define PIECE_KIN
#include "Piece.h"
/**
 *@clss   「金」の駒クラス
 */

class PieceGoldgeneral :public Piece
{
public:
	PieceGoldgeneral();
	~PieceGoldgeneral() {}

private:
	//!移動範囲配列
	static const __int8 m_move_[MOVE_MAX_Y][MOVE_MAX_X]; //!先手

};

#endif