#include "DataBase.h"
#include "World.h"
#include <iostream>

/* �w��񏉊��� */
StationInfo m_station_info[STATION_NUM] =
{
    //�w��(�E��]�ŏ������A����]���͉�����)
    {"����"    ,   2},
    {"�L�y��"  ,   2},
    {"�V��"    ,   2},
    {"�l����"  ,   2},
    {"�c��"    ,   2},
    {"�i��"    ,   3},
    {"���"    ,   2},
    {"�ܔ��c"  ,   2},
    {"�ڍ�"    ,   3},
    {"�b���"  ,   2},
    {"�a�J"    ,   2},
    {"���h"    ,   2},
    {"��X��"  ,   2},
    {"�V�h"    ,   2},
    {"�V��v��",   2},
    {"���c�n��",   2},
    {"�ڔ�"    ,   3},
    {"�r��"    ,   2},
    {"���"    ,   2},
    {"����"    ,   2},
    {"�"    ,   2},
    {"�c�["    ,   2},
    {"�����既",   1},
    {"���既"  ,   2},
    {"��J"    ,   2},
    {"���"    ,   2},
    {"��k��"  ,   2},
    {"�H�t��"  ,   2},
    {"�_�c"    ,   1}
};


void DataBase::StepChange()
{
    switch (m_step)
    {
    case DataBase::STEP_INPUT:
        Init();
    case DataBase::STEP_CALUCULATION:
        Caluculation();
    case DataBase::STEP_SET:
        SetTotalValue();
    default:
        break;
    }
}

void DataBase::Init()
{   
    /* ���͂������O��ۑ� */
    strcpy_s(input_start_station, g_inputter.GetStartStationName());
    strcpy_s(input_end_station, g_inputter.GetEndStationName());

    /* �n�܂�ƏI���̉w���������v�f����ۑ� */
    for (int i = 0; i < STATION_NUM; i++)
    {
        if (strcmp(g_inputter.GetStartStationName(), m_station_info[i].station) == 0)
        {
            m_start_station = i;   //�n�܂�
        }
        if (strcmp(g_inputter.GetEndStationName(), m_station_info[i].station) == 0)
        {
            m_end_station = i;    //�I���
        }
    }

    /* ���̃X�e�b�v�� */
    m_step = STEP_CALUCULATION;
}

/* �v�Z�֐� */
void DataBase::Caluculation()
{
    /* �E��莞�A�z��̍Ōォ��ŏ��܂Œʂ�Ƃ�(��28�`3�Ȃ�) */
    if (m_end_station - m_start_station < 0)
    {
        /* �I���̉w�`�z��̍Ō�̉w�܂ł̍��v���o�� */
        for (int i = m_end_station; i < STATION_NUM; i++)
        {
            m_right_total_value += m_station_info[i].Spin;    //���̉w�܂Ŋ|���鎞�Ԃ����v�l�ɑ���
        }
        /* �z��̍ŏ��̉w�`�n�܂�̉w�܂ł̍��v���o�� */
        for (int i = START_STATION; i < m_start_station; i++)
        {
            m_right_total_value += m_station_info[i].Spin;    //���̉w�܂Ŋ|���鎞�Ԃ����v�l�ɑ���
        }
    }

    /* �E��莞 */
    for (int i = m_start_station; i < m_end_station; i++)
    {
        m_right_total_value += m_station_info[i].Spin;
    }


    /* ����莞�A�z��̍ŏ�����Ō�܂Œʂ�Ƃ�(��3�`28�Ȃ�) */
    if (m_end_station - m_start_station > 0)
    {
        /* �I���̉w�`�z��̍Ō�̉w�܂ł̍��v���o�� */
        for (int i = STATION_NUM; i > m_end_station; i--)
        {
            m_left_total_value += m_station_info[i].Spin;   //���̉w�܂Ŋ|���鎞�Ԃ����v�l�ɑ���
        }

        /* �z��̍ŏ��̉w�`�n�܂�̉w�܂ł̍��v���o�� */
        for (int i = m_start_station; i > START_STATION; i--)
        {
            m_left_total_value += m_station_info[i].Spin;   //���̉w�܂Ŋ|���鎞�Ԃ����v�l�ɑ���
        }
    }

    /*�@����莞 */
    for (int i = m_end_station; i < m_start_station; i--)
    {
        m_left_total_value += m_station_info[i].Spin;
    }
    m_step = STEP_SET;

}

/* �l�킽���֐� */
void DataBase::SetTotalValue()
{
    g_drawer.SetRightTotalValue(m_right_total_value, m_left_total_value);
}


