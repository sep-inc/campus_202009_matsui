#ifndef SYOUGI_PIECE_KIN
#define SYOUGI_PIECE_KIN
#include "SyougiPiece.h"
/**
 *@clss   「金」の駒クラス
 */

class SyougiPieceGoldgeneral :public SyougiPiece
{
public:
	SyougiPieceGoldgeneral();
	~SyougiPieceGoldgeneral() {}

private:
	//!移動範囲配列
	static const __int8 m_move_[PIECE_MOVE_MAX_Y][PIECE_MOVE_MAX_X]; //!先手

};

#endif