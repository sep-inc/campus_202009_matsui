#include "Player.h"
#include "../Definition.h"
#include "../Entity.h"
#include "../Object/Piece_King.h"
#include "../Object/Piece_Knight.h"
#include "../Object/Piece_Goldgeneral.h"
#include "../Object/Piece_Pawn.h"
#include <stdio.h>

//!移動処理
void Player::Move(Board* bord_)
{
	//!移動先を盤クラスに送る
	bord_->SetPiecePos(m_next_pos, m_piece_type, m_my_player_type);
}

//!指定箇所調査
void Player::SearchBord(Board* bord_,Vec2 pos_)
{
	m_piece_type = bord_->SearchPiece(pos_);    //!駒の種類判別
	m_player_type = bord_->SearchPlayer(pos_);  //!先手の駒か後手の駒か判別
}

//!勝敗判定
bool Player::Judgment(Board* bord_)
{
	//!盤クラスに移動後の結果(王を取ったか)を返すようにする
	if (bord_->GetWinner() == m_my_player_type)
	{
		//!勝者表示
		if (m_my_player_type == FIRST)
		{
			printf("先手の勝ちです。\n");
		}
		else
		{
			printf("後手の勝ちです。\n");
		}
		//!GameControllerに結果を返す
		return true;
	}

	return false;
}

