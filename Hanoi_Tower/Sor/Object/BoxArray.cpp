#include "BoxArray.h"
#include "../Typedef.h"
#include <string.h>

/* �X�e�b�v���� */
void BoxArray::StepChange()
{
	switch (m_step)
	{
	case Step::STEP_INIT:      //������
		Init();
		break;
	case Step::STEP_SEARCH:    //����
		Search();
        break;
	default:
		break;
	}
}

/* ������ */
void BoxArray::Init()
{
	Vec pos = Vec(1, 2); //���[�̔��̍��W�ŏ�����

	for (int i = 0; i < BOX_NUM; i++)
	{
		m_box[i].Init(pos, BOX_WIDTH, BOX_HEIGHT);
        pos.x += BOX_WIDTH + 1; //Box�̉���+1�̊��o�Ŕz�u����
	}

    /* ���̃X�e�b�v�� */
    m_step = Step::STEP_SEARCH;
}


/* ���� */
void BoxArray::Search()
{
    /* �I������ */
    if (SearchRightBox() == true)
    {
        m_end = true;
    }

}

/* �w�肵��box�̍��W���璆�g�𒲂ׂ� */
unsigned __int8 BoxArray::SearchBox(unsigned __int8 pos_x_)
{
    unsigned __int8 disk_size = 0;   //disk�̉�����Ԃ��p

    /* for����m_box_buffer�̒��g�𒲂ׂ�(��̒i���璲�ׂ�) */
    for (int y = BUFFER_BOX_POS_Y; y < BOX_WIDTH; y++)
    {
        /* �w�肵��box��x���W�` Box�̉��� */
        for (int x = pos_x_; x < pos_x_ + BOX_WIDTH; x++)
        {
            if (m_box_buffer[y][x] == OBJECT_TYPE::DISK)
            {
                disk_size++;   //�~�Ղ̉������L����
            }
        }

        /* disk�̉�����0�ȏ�Ȃ�(disk�������) */
        if (disk_size > 0)
        {
            return disk_size;   //�ړ����̉~�Ղ̃T�C�Y��Ԃ�
        }
    }

    /* disk���Ȃ���Έ�ԉ��ɒu����悤�ɃT�C�Y���ł������Ēu����悤�ɂ��� */
    return DISK_MAX_WIDTH;
}

/* �E�[�̔��ɂ��ׂẲ~�Ղ����邩�ǂ������ׂ鏈�� */
bool BoxArray::SearchRightBox()
{
    m_disk_counter = 0;

    for (int y = BUFFER_BOX_POS_Y; y <= BUFFER_BOX_POS_Y + BOX_HEIGHT; y++)
    {
        /* x���͔��̐^�񒆂����m���΂悢�̂ŌŒ� */
        if (m_box_buffer[y][15] == OBJECT_TYPE::DISK)
        {
            m_disk_counter++;
        }
    }

    /* �~�Ղ����ׂĉE�ɂ���Ƃ�����Ƃ� */
    if (m_disk_counter >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }

}

/* �ړ����邽�߂ɔ��̒��g�𒲂ׂ� */
bool BoxArray::SearchMoveDiskSize(unsigned __int8 disk_width,unsigned __int8 now_number_,unsigned __int8 next_number_)
{
    m_now_investigation_pos = SearchPos_X(now_number_);     //�ړ����̊���W(����)����  
    m_next_investigation_pos = SearchPos_X(next_number_);   //�ړ���̊���W(����)����    


    __int8 m_now_disk_size = 0;    //�ړ�����disk�̉����ۑ��p
    __int8 m_next_disk_size = 0;   //�ړ����disk�̉����ۑ��p

    m_now_disk_size = SearchBox(m_now_investigation_pos);     //�ړ���box�̒��g�𒲂ׂ�
    m_next_disk_size = SearchBox(m_next_investigation_pos);   //�ړ���box�̒��g�𒲂ׂ�

    /* �ړ�����disk�����݁A���ړ����disk��u����Ƃ�*/
    if (m_now_disk_size == disk_width && m_next_disk_size > disk_width)
    { 
        return true;
    }
    else
    {
        return false;
    }
}

/* �ړ����̊���W�X�V�֐� */
unsigned __int8 BoxArray::SearchPos_X(unsigned __int8 number_)
{
    unsigned __int8 investigation_pos = 0;   //�����pboxpos

    switch (number_)
    {
    case 1://1�Ԃ̎�
        investigation_pos = 1;   //���̍��[�ɐݒ�
        break;
    case 2: //2�Ԃ̎�
        investigation_pos = 7;   //���̍��[�ɐݒ�
        break;
    case 3: //3�Ԃ̎�
        investigation_pos = 13;  //���̍��[�ɐݒ�
        break;
    default:
        break;
    }

    return investigation_pos;
}

/* �ړ����disk�̒u����y���W������ */
unsigned __int8 BoxArray::SetDiskPos_Y()
{
    unsigned __int8 disk_size = 0;
    unsigned __int8 pos_y = 0;

    /* for����m_box_buffer�̒��g�𒲂ׂ�(��̒i���璲�ׂ�) */
    for (int y = BUFFER_BOX_POS_Y; y < BOX_WIDTH; y++)
    {
        /* �ړ���̍��W�` Box�̉��� */
        for (int x = m_next_investigation_pos; x < m_next_investigation_pos + 5; x++)
        {
            if (m_box_buffer[y][x] == OBJECT_TYPE::DISK)
            {
                disk_size++;   //disk�̃T�C�Y
            }
        }

        /* disk������������ */
        if (disk_size > 0)
        {
            pos_y = y - 1;  //��������disk�̏�ɔz�u���邽��-1����
            return pos_y;   
        }
        else
        {
            pos_y = y;      //������Ȃ���Έ�ԉ��ɔz�u
        }
    }

    return pos_y;
}

/* �~�Ղ𒲍��pBox�z��ɑ�� */
void BoxArray::SetUpDisk(Vec pos, unsigned  __int8 width_, unsigned  __int8 height_)
{
    for (int i = 0; i < width_; i++)
    {
        m_box_buffer[pos.y][pos.x + i] = OBJECT_TYPE::DISK;
    }
}

/* �`��z��ɑ�� */
void BoxArray::SetUpDrawBuffer()
{
	for (int i = 0; i < BOX_NUM; i++)
	{
		m_box[i].SetUpBuffer();
	}
}

/* �����pBox�z�񏉊��� */
void BoxArray::ClearBoxBuffer()
{
    memset(&m_box_buffer, 0, sizeof(m_box_buffer));
}
