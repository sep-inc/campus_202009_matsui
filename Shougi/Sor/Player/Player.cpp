#include "Player.h"
#include "../Definition.h"
#include "../Entity.h"
#include "../Object/Piece_King.h"
#include "../Object/Piece_Knight.h"
#include "../Object/Piece_Goldgeneral.h"
#include "../Object/Piece_Pawn.h"
#include <stdio.h>

//!�ړ�����
void Player::Move(Board* bord_)
{
	//!�ړ����ՃN���X�ɑ���
	bord_->SetPiecePos(m_next_pos, m_piece_type, m_my_player_type);
}

//!�w��ӏ�����
void Player::SearchBord(Board* bord_,Vec2 pos_)
{
	m_piece_type = bord_->SearchPiece(pos_);    //!��̎�ޔ���
	m_player_type = bord_->SearchPlayer(pos_);  //!���̋���̋����
}

//!���s����
bool Player::Judgment(Board* bord_)
{
	//!�ՃN���X�Ɉړ���̌���(�����������)��Ԃ��悤�ɂ���
	if (bord_->GetWinner() == m_my_player_type)
	{
		//!���ҕ\��
		if (m_my_player_type == FIRST)
		{
			printf("���̏����ł��B\n");
		}
		else
		{
			printf("���̏����ł��B\n");
		}
		//!GameController�Ɍ��ʂ�Ԃ�
		return true;
	}

	return false;
}

