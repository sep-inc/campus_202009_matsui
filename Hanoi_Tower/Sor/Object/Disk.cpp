#include "Disk.h"
#include "../Typedef.h"

/* ������ */
void Disk::Init(Vec pos_, unsigned  __int8 width_, unsigned  __int8 height_)
{
	ObjectBase::Init(pos_, width_, height_);
}

/* �`����W���� */
void Disk::SetUpBuffer()
{
	g_drawer.SetUpBuffer(m_pos, m_width, m_height, OBJECT_TYPE::DISK);
}

/* ����W�ύX�֐� */
void Disk::SetPos(unsigned __int8 number_, unsigned __int8 width_)
{
    /*  ��x���[��Box�ɍ��W�����Z�b�g���� */
    switch (width_)
    {
    case 1:
        m_pos.x = 3;   //���T�C�Y
        break;
    case 3:
        m_pos.x = 2;   //���T�C�Y
        break;
    case 5:
        m_pos.x = 1;   //��T�C�Y
        break;
    default:
        break;
    }

    switch (number_)
    {
    case 1:
        m_pos.x += 0;   //1�Ԗڂ̔���I�񂾎�
        break;
    case 2:
        m_pos.x += 6;   //2�Ԗڂ̔���I�񂾎�
        break;
    case 3:
        m_pos.x += 12;  //3�Ԗڂ̔���I�񂾎�
        break;
    default:
        break;
    }

    m_pos.y = g_boxarray.SetDiskPos_Y();
}

