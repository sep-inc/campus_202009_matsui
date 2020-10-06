#ifndef PIECE_KEIMA
#define PIECE_KEIMA
#include "Piece.h"
/**
 *@clss   「桂馬」の駒クラス
 */

//!桂馬
class PieceKnight :public Piece
{
public:
	PieceKnight();
	~PieceKnight() {}
private:
	//!移動範囲配列
	static const __int8 m_move_[MOVE_MAX_Y][MOVE_MAX_X]; //!先手

};

#endif