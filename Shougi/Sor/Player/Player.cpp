#include "Player.h"
#include "../Definition.h"
#include "../Entity.h"
#include "../Object/Piece_King.h"
#include "../Object/Piece_Knight.h"
#include "../Object/Piece_Goldgeneral.h"
#include "../Object/Piece_Pawn.h"
#include <stdio.h>

//!�X�V����
void Player::Update(Bord* bord_, Piece* piece_[])
{
	//!�ړ���������I�ђ������p�Ƀ��[�v����
	while (true)
	{
		//!�ړ��������I��
		MoveSourceSelect(bord_);

		//!�ړ������
		if (NextMoveSelect(bord_, piece_) == true)
		{
			break;
		}

		printf("\n");
	}

	//!�ړ�
	Move(bord_);
}

//!�ړ�����
void Player::Move(Bord* bord_)
{
	//!�ړ����ՃN���X�ɑ���
	bord_->SetPiecePos(m_next_pos, m_piece_type, m_my_player_type);
}

//!�w��ӏ�����
void Player::SearchBord(Bord* bord_)
{
	m_piece_type = bord_->SearchPiece(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());    //!��̎�ޔ���
	m_player_type = bord_->SearchPlayer(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //!���̋���̋����
}

//!���s����
bool Player::Judgment(Bord* bord_)
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

