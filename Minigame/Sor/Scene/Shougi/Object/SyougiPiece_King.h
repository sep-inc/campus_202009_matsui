#ifndef SYOUGI_PIECE_OU
#define SYOUGI_PIECE_OU
#include "SyougiPiece.h"
/**
 *@clss   「王」の駒クラス
 */
class SyougiPieceKing :public SyougiPiece
{
public:
	SyougiPieceKing();
	~SyougiPieceKing() {}


private:
	//!移動範囲配列
	static const __int8 m_move_[PIECE_MOVE_MAX_Y][PIECE_MOVE_MAX_X]; //!先手


};


#endif