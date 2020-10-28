#ifndef SYOUGI_PIECE_KEIMA
#define SYOUGI_PIECE_KEIMA
#include "SyougiPiece.h"
/**
 *@clss   「桂馬」の駒クラス
 */

 //!桂馬
class SyougiPieceKnight :public SyougiPiece
{
public:
	SyougiPieceKnight();
	~SyougiPieceKnight() {}
private:
	//!移動範囲配列
	static const __int8 m_move_[PIECE_MOVE_MAX_Y][PIECE_MOVE_MAX_X]; //!先手

};

#endif