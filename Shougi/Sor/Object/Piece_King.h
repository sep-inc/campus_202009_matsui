#ifndef PIECE_OU
#define PIECE_OU
#include "Piece.h"
/**
 *@clss   「王」の駒クラス
 */
class PieceKing :public Piece
{
public:
	PieceKing();
	~PieceKing() {}

	
private:
	//!移動範囲配列
	static const __int8 m_move_[MOVE_MAX_Y][MOVE_MAX_X]; //!先手


};


#endif