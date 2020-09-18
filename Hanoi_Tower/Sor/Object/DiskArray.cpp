#include "DiskArray.h"
#include "../Typedef.h"

/* �X�e�b�v���� */
void DiskArray::StepChange()
{
	switch (m_step)
	{
	case DiskArray::STEP_INIT:    //������
		Init();
		break;
	case DiskArray::STEP_MOVE:    //�ړ�
		Move();
		break;
	default:
		break;
	}
}

/* ������ */
void DiskArray::Init()
{
	Vec pos = Vec(3,2);  //�ŏ��͈�ԏ�ɒu���Ă���~�Ղ̍��W(�������_�Ƃ���)�ŏ�����

	__int8 width = SMALL_DISK_WIDTH;   //�ŏ��͈�ԏ�ɒu���Ă���~�Ղ�Width�ŏ�����

	/* �~�Ղ̐����� */
	for (int i = 0; i < DISK_NUM; i++)
	{
		m_disk[i].Init(pos, width, DISK_HEIGHT);

		pos.x--;  //�������_�Ƃ����ꍇx���W�͑傫���Ȃ�ɂ�L���Ȃ邽��
		pos.y++;  //���ɐς�ł��邽��
		
		if (i == 0)
		{
			width = NOMAL_DISK_WIDTH;  //���ʃT�C�Y
		}
		else if (i == 1)
		{
			width = BIG_DISK_WIDTH;   //��T�C�Y
		}
	}

	/* �����p�z��ɑ�� */
	SetUpBox();

	/* ���̃X�e�b�v�� */
	m_step = STEP_MOVE;
}

/* �ړ����� */
void DiskArray::Move()
{

	for (int num = 0; num < DISK_NUM; num++)
	{
		/* �������~�Ղ����𒲂ׂ��~�ՂƓ����T�C^�Y(��ԏ�ɉ~�Ղ�����)�Ȃ瓮���� */
		if (g_boxarray.SearchMoveDiskSize(m_disk[num].GetWidth(), g_inputter.GetStartNumber(), g_inputter.GetEndNumber()) == true)
		{
			/* ���W�X�V */
			m_disk[num].SetPos(g_inputter.GetEndNumber(), m_disk[num].GetWidth());
			g_boxarray.ClearBoxBuffer();
			break;
		}
	}

	SetUpBox();

}

/* �`����W�X�V */
void DiskArray::SetUpDrawBuffer()
{
	for (int i = 0; i < DISK_NUM; i++)
	{
		m_disk[i].SetUpBuffer();
	}
}

/* �����p�z��ɉ~�Ղ��� */
void DiskArray::SetUpBox()
{
	for (int i = 0; i < DISK_NUM; i++)
	{
		g_boxarray.SetUpDisk(m_disk[i].GetPos(), m_disk[i].GetWidth(), DISK_HEIGHT);
	}
}
