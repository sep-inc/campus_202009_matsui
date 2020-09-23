#include "Bord.h"
#include "../Entity.h"

//!�������֐�
void Bord::Init()
{
	__int8 number = 1;  //!�u����ꏊ�ԍ���1�`9�Œ�`���邽��

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			m_bord_info[y][x].m_put_number = number;  //!�u����ꏊ�ԍ�
			m_bord_info[y][x].m_put_object = 0;       //!�����Տ�ɒu���Ă��Ȃ��̂�0������

			number++;
		}
	}
}

//!�����֐�
bool Bord::Search()
{
	//!��������
	if (EndSearch(OBJECT_TYPE::PLAYER_PIECE) == true)
	{
		g_drawer.DrawJudgment(WIN);  //!�����\��
		return true;
	}
	//!��������
	if(EndSearch(OBJECT_TYPE::ENEMY_PIECE) == true)
	{
		g_drawer.DrawJudgment(LOSE); //!�����\��
		return true;
	}
	//!������������
	else if (DrawSearch() == true)
	{
		g_drawer.DrawJudgment(DRAW); //!�����\��
		return true;
	}

	return false;
}

//!�I������(���s)�֐�
bool Bord::EndSearch(__int8 object)
{
	__int8 piece_count_x = 0;  //!���̔���p
	__int8 piece_count_y = 0;  //!�c�̔���p


	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			//!���Ɏw�肵����u���Ă���ꍇ�J�E���g+1
			if (m_bord_info[y][x].m_put_object == object)
			{
				piece_count_x++;

				//!�����3�ȏ゠��ꍇ�I��
				if (piece_count_x == 3)
				{
					return true;
				}
			}
			//!�c�Ɏw�肵����u���Ă���ꍇ�J�E���g+1
			else if (m_bord_info[x][y].m_put_object == object)
			{
				piece_count_y++;

				//!�����3�ȏ゠��ꍇ�I��
				if (piece_count_y == 3)
				{
					return true;
				}
			}
		}
		piece_count_x = 0;
		piece_count_y = 0;
	}

	//!�E�������̎΂߂̔���
	if (m_bord_info[0][0].m_put_object == object &&
		m_bord_info[1][1].m_put_object == object &&
		m_bord_info[2][2].m_put_object == object)
	{
		return true;
	}
	//!���������̎΂߂̔���
	else if (m_bord_info[0][2].m_put_object == object &&
		     m_bord_info[1][1].m_put_object == object &&
		     m_bord_info[2][0].m_put_object == object)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//!�I������(��������)�֐�
bool Bord::DrawSearch()
{
	//!�Տ�ɋ���ׂĒu����Ă��āA�����3�ȏセ����Ă��Ȃ��ꍇtrue
	if (SearchNumber() == false && g_bord.EndSearch(OBJECT_TYPE::PLAYER_PIECE) == false
		&& g_bord.EndSearch(OBJECT_TYPE::ENEMY_PIECE) == false)
	{
		return true;
	}
	return false;
}

//!�u���邩�ǂ�������֐�
bool Bord::PutSearch(__int8 input_font,__int8 input_number)
{	
	//!�w�肵���ʒu�ɋ�Ȃ��ꍇ��0
	if (m_bord_info[input_number][input_font].m_put_number > 0)
	{
		//!���u�����ꏊ�ɂ�-1�ɕς��Ď��̃t���[���ȍ~�͒u���Ȃ��悤�ɂ���
		m_bord_info[input_number][input_font].m_put_number = -1;  

		return true;
	}
	
	return false;
	
}

//!�z�u�ꏊ�����֐�
bool Bord::SearchNumber()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			//!�u����ꏊ������̂����ׂ�
			if (m_bord_info[y][x].m_put_number >= 0)
			{
				return true;
			}
		}
	}

	return false;
}

//!�������W����֐�
void Bord::SetPiecePos(Vec piece_,__int8 object_)
{
	m_bord_info[piece_.y][piece_.x].m_put_object = object_;
}

