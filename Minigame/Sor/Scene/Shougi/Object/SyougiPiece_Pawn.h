#ifndef SYOUGI_PIECE_HU
#define SYOUGI_PIECE_HU
#include "SyougiPiece.h"
/**
 *@clss   「歩」の駒クラス
 */

#define PAWN_NUM 4  //!歩の数

class SyougiPiecePawn :public SyougiPiece
{
public:
	SyougiPiecePawn();
	~SyougiPiecePawn() {}

private:
	//!移動範囲配列
	static const __int8 m_move_[PIECE_MOVE_MAX_Y][PIECE_MOVE_MAX_X]; //!先手

};

#endif