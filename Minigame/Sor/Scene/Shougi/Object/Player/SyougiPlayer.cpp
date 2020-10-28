#include "SyougiPlayer.h"
#include "../SyougiPiece_King.h"
#include "../SyougiPiece_Knight.h"
#include "../SyougiPiece_Goldgeneral.h"
#include "../SyougiPiece_Pawn.h"
#include <stdio.h>

//!移動処理
void SyougiPlayer::Move(SyougiBoard* bord_)
{
	//!移動先を盤クラスに送る
	bord_->SetPiecePos(m_next_pos, m_piece_type, m_my_player_type);
}

//!指定箇所調査
void SyougiPlayer::SearchBord(SyougiBoard* bord_, Vec2 pos_)
{
	m_piece_type = bord_->SearchPiece(pos_);    //!駒の種類判別
	m_player_type = bord_->SearchPlayer(pos_);  //!先手の駒か後手の駒か判別
}

//!勝敗判定
bool SyougiPlayer::Judgment(SyougiBoard* bord_)
{
	//!盤クラスに移動後の結果(王を取ったか)を返すようにする
	if (bord_->GetWinner() == m_my_player_type)
	{
		//!GameControllerに結果を返す
		return true;
	}

	return false;
}

