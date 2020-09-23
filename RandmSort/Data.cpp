#include "Data.h"
#include <string.h>
#include <stdio.h>
#include <random>
#include <time.h>

/* �X�e�b�v���� */
void Data::StepChange()
{
	switch (m_step)
	{
	case STEP_INIT:       //������
		Init();
	case STEP_UPDATE:    //�X�V
		Update();
	case STEP_DRAW:      //�`��
		Draw();
	default:
		break;
	}
}

/* ������ */
void Data::Init()
{
	/* �z��̒��g��0������ */
	memset(&m_integer_array, 0, sizeof(m_integer_array));

	/* �������o�z�񏉊��� */
	for (int i = 0; i < 100; i++)
	{
		transfer_box[i] = i;   //0�`99
	}

	/* �e�[�u�������� */
	srand((unsigned)time(NULL));

	/* ���̃X�e�b�v�� */
	m_step = STEP_UPDATE;
}

/* �X�V */
void Data::Update()
{
	for (__int8 i = 0; i < ELEMENT; i++)
	{
		m_integer_array[i].randm = RandmNumber();                        //�������
		m_integer_array[i].sort = CopyArray(m_integer_array[i].randm);   //�����z����\�[�g�p�z��ɃR�s�[
	}
	
	SortArray();      //�\�[�g�z��������ŕ��ёւ���

	/* ���̃X�e�b�v�� */
	m_step = STEP_DRAW;
}

/* ��������֐� */
__int8 Data::RandmNumber()
{

	__int8 array_ = 0;  //�ۑ��p

	/* �������� */
	array_ = rand() % 100;

	for (int i = 0; i < 100; i++)
	{
		/* ��������������΂��̐���Ԃ� */
		if (transfer_box[i] == array_)
		{
			transfer_box[i] = -1;   //���o�������͔��Ȃ��悤��-1�ɂ���
			return array_;
		}
	}
}


/* �����z��R�s�[�֐� */
__int8 Data::CopyArray(__int8 copy_array_)
{
	__int8 array_ = 0;    //�ۑ��p

	/* �����z����\�[�g�p�z��ɃR�s�[ */
	array_ = copy_array_;

	return array_;
}

/* �\�[�g�z��\�[�g�֐� */
void Data::SortArray()
{
	__int8 save_number = 0;  //����ւ��ۑ��p

	for (__int8 i = 0; i < ELEMENT; i++)
	{
		for (__int8 j = i + 1; j < ELEMENT; j++)
		{
			/* ���݂̗v�f�̒��g�����̗v�f�̐���菬�����ꍇ */
			if (m_integer_array[i].sort < m_integer_array[j].sort)
			{
				/* ����ւ� */
				save_number = m_integer_array[i].sort;
				m_integer_array[i].sort = m_integer_array[j].sort;
				m_integer_array[j].sort = save_number;
			}
		}
	}

}

/* �\�� */
void Data::Draw()
{
	printf("�����\��\n");
	for (__int8 i = 0; i < ELEMENT; i++)
	{	
		printf("%d,", m_integer_array[i].randm);
	}

	getchar();

	printf("�\�[�g��\n");

	for (__int8 i = 0; i < ELEMENT; i++)
	{
		printf("%d,", m_integer_array[i].sort);
	}
	printf("\n\n");
	
}
