#include "Drawer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* �`��p�z�񏉊��� */
void Drawer::Init()
{

	memset(&m_blank_map, OBJECTKIND::BLANK, sizeof(m_blank_map));  //�N���A�p�z�񏉊�

	/* ��(�t���[��)�̔z�u */
	for (int x = START_UNIT; x < NUM_UNIT_X; x++)
	{
		m_map[START_UNIT][x].m_kind =  OBJECTKIND::WALL ;    //���
		m_map[NUM_UNIT_Y - 1][x].m_kind = OBJECTKIND::WALL;  //����
	}

	for (int y = START_UNIT; y < NUM_UNIT_Y; y++)
	{	
		m_map[y][START_UNIT].m_kind =  OBJECTKIND::WALL;     //����
		m_map[y][NUM_UNIT_X - 1].m_kind = OBJECTKIND::WALL;  //�E��
	}

	memcpy(&m_blank_map, &m_map, sizeof(m_map)); //�N���A�p�z��ɕ�(�s�ς�Object)���R�s�[
}

/* �`�� */
void Drawer::Draw()
{

	for (int y = START_UNIT; y < NUM_UNIT_Y; y++)
	{
		for (int x = START_UNIT; x < NUM_UNIT_X; x++)
		{
			if (m_map[y][x].m_kind == OBJECTKIND::WALL)
			{
				printf("��");          //1=�O�g
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BLOCK)
			{
				printf("��");          //1=�O�g
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BAR)
			{
				printf("��");          //1=�O�g
			}
			else if (m_map[y][x].m_kind == OBJECTKIND::BALL)
			{
				printf("��");          //1=�O�g
			}
			else
			{
				printf("�@");          //��
			}
		}
		printf("\n");
	}
}


/* �`��p�z��N���A */
void Drawer::BufferClear()
{
	memcpy(&m_map, &m_blank_map, sizeof(m_blank_map));
}


/* World�z���`����W�ɕϊ�(�eObject�ōs�� )*/
void Drawer::SetUpBuffer(Vec2 pos_, OBJECTKIND kind_, int width_)
{
	int x = (pos_.X + UNIT_X) / UNIT_X;
	int y = (pos_.Y + UNIT_Y) / UNIT_Y;

	int num_x = width_ / UNIT_X;

	/* �`��ɕK�v�Ȑ����� */
	for (int x2 = START_UNIT; x2 < num_x; x2++)
	{
		m_map[y][x + x2].m_kind = kind_;
	}
	
}

