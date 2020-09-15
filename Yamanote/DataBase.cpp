#include "DataBase.h"
#include "World.h"
#include <iostream>

/* ‰wξ•ρ‰ϊ‰» */
StationInfo m_station_info[STATION_NUM] =
{
    //‰w–Ό(‰E‰ρ“]‚Ε‰ϊ‰»A¶‰ρ“]‚Ν‰Ί‚©‚η)
    {"“‹"    ,   2},
    {"—Ly’¬"  ,   2},
    {"V‹΄"    ,   2},
    {"•lΌ’¬"  ,   2},
    {"“c’¬"    ,   2},
    {"•iμ"    ,   3},
    {"‘εθ"    ,   2},
    {"ά”½“c"  ,   2},
    {"–Ϊ•"    ,   3},
    {"b”δυ"  ,   2},
    {"a’J"    ,   2},
    {"΄h"    ,   2},
    {"‘γX–Ψ"  ,   2},
    {"Vh"    ,   2},
    {"V‘ε‹v•Ϋ",   2},
    {"‚“c”nκ",   2},
    {"–Ϊ”’"    ,   3},
    {"’r‘ά"    ,   2},
    {"‘ε’Λ"    ,   2},
    {"‘ƒ›"    ,   2},
    {"‹ξ"    ,   2},
    {"“c’["    ,   2},
    {"Ό“ϊ•ζ—Ά",   1},
    {"“ϊ•ζ—Ά"  ,   2},
    {"ις’J"    ,   2},
    {"γ–μ"    ,   2},
    {"δ“k’¬"  ,   2},
    {"H—t΄"  ,   2},
    {"_“c"    ,   1}
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
    /* “ό—Ν‚µ‚½–Ό‘O‚π•Ϋ‘¶ */
    strcpy_s(input_start_station, g_inputter.GetStartStationName());
    strcpy_s(input_end_station, g_inputter.GetEndStationName());

    /* n‚ά‚θ‚ΖI‚ν‚θ‚Μ‰w–Ό‚ª“―‚¶—v‘f”‚π•Ϋ‘¶ */
    for (int i = 0; i < STATION_NUM; i++)
    {
        if (strcmp(g_inputter.GetStartStationName(), m_station_info[i].station) == 0)
        {
            m_start_station = i;   //n‚ά‚θ
        }
        if (strcmp(g_inputter.GetEndStationName(), m_station_info[i].station) == 0)
        {
            m_end_station = i;    //I‚ν‚θ
        }
    }

    /* ‚ΜƒXƒeƒbƒv‚Φ */
    m_step = STEP_CALUCULATION;
}

/* vZΦ” */
void DataBase::Caluculation()
{
    /* ‰E‰ρ‚θA”z—ρ‚ΜΕγ‚©‚ηΕ‰‚ά‚Ε’Κ‚ι‚Ζ‚«(—α28`3‚Θ‚Η) */
    if (m_end_station - m_start_station < 0)
    {
        /* I‚ν‚θ‚Μ‰w`”z—ρ‚ΜΕγ‚Μ‰w‚ά‚Ε‚Μ‡v‚πo‚· */
        for (int i = m_end_station; i < STATION_NUM; i++)
        {
            m_right_total_value += m_station_info[i].Spin;    //‚Μ‰w‚ά‚Ε|‚©‚ιΤ‚π‡v’l‚Ι‘«‚·
        }
        /* ”z—ρ‚ΜΕ‰‚Μ‰w`n‚ά‚θ‚Μ‰w‚ά‚Ε‚Μ‡v‚πo‚· */
        for (int i = START_STATION; i < m_start_station; i++)
        {
            m_right_total_value += m_station_info[i].Spin;    //‚Μ‰w‚ά‚Ε|‚©‚ιΤ‚π‡v’l‚Ι‘«‚·
        }
    }

    /* ‰E‰ρ‚θ */
    for (int i = m_start_station; i < m_end_station; i++)
    {
        m_right_total_value += m_station_info[i].Spin;
    }


    /* ¶‰ρ‚θA”z—ρ‚ΜΕ‰‚©‚ηΕγ‚ά‚Ε’Κ‚ι‚Ζ‚«(—α3`28‚Θ‚Η) */
    if (m_end_station - m_start_station > 0)
    {
        /* I‚ν‚θ‚Μ‰w`”z—ρ‚ΜΕγ‚Μ‰w‚ά‚Ε‚Μ‡v‚πo‚· */
        for (int i = STATION_NUM; i > m_end_station; i--)
        {
            m_left_total_value += m_station_info[i].Spin;   //‚Μ‰w‚ά‚Ε|‚©‚ιΤ‚π‡v’l‚Ι‘«‚·
        }

        /* ”z—ρ‚ΜΕ‰‚Μ‰w`n‚ά‚θ‚Μ‰w‚ά‚Ε‚Μ‡v‚πo‚· */
        for (int i = m_start_station; i > START_STATION; i--)
        {
            m_left_total_value += m_station_info[i].Spin;   //‚Μ‰w‚ά‚Ε|‚©‚ιΤ‚π‡v’l‚Ι‘«‚·
        }
    }

    /*@¶‰ρ‚θ */
    for (int i = m_end_station; i < m_start_station; i--)
    {
        m_left_total_value += m_station_info[i].Spin;
    }
    m_step = STEP_SET;

}

/* ’l‚ν‚½‚µΦ” */
void DataBase::SetTotalValue()
{
    g_drawer.SetRightTotalValue(m_right_total_value, m_left_total_value);
}


