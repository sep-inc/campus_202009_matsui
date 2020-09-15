#include "DataBase.h"
#include "World.h"
#include <iostream>

/* 駅情報初期化 */
StationInfo m_station_info[STATION_NUM] =
{
    //駅名(右回転で初期化、左回転時は下から)
    {"東京"    ,   2},
    {"有楽町"  ,   2},
    {"新橋"    ,   2},
    {"浜松町"  ,   2},
    {"田町"    ,   2},
    {"品川"    ,   3},
    {"大崎"    ,   2},
    {"五反田"  ,   2},
    {"目黒"    ,   3},
    {"恵比寿"  ,   2},
    {"渋谷"    ,   2},
    {"原宿"    ,   2},
    {"代々木"  ,   2},
    {"新宿"    ,   2},
    {"新大久保",   2},
    {"高田馬場",   2},
    {"目白"    ,   3},
    {"池袋"    ,   2},
    {"大塚"    ,   2},
    {"巣鴨"    ,   2},
    {"駒込"    ,   2},
    {"田端"    ,   2},
    {"西日墓里",   1},
    {"日墓里"  ,   2},
    {"鶯谷"    ,   2},
    {"上野"    ,   2},
    {"御徒町"  ,   2},
    {"秋葉原"  ,   2},
    {"神田"    ,   1}
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
    /* 入力した名前を保存 */
    strcpy_s(input_start_station, g_inputter.GetStartStationName());
    strcpy_s(input_end_station, g_inputter.GetEndStationName());

    /* 始まりと終わりの駅名が同じ要素数を保存 */
    for (int i = 0; i < STATION_NUM; i++)
    {
        if (strcmp(g_inputter.GetStartStationName(), m_station_info[i].station) == 0)
        {
            m_start_station = i;   //始まり
        }
        if (strcmp(g_inputter.GetEndStationName(), m_station_info[i].station) == 0)
        {
            m_end_station = i;    //終わり
        }
    }

    /* 次のステップへ */
    m_step = STEP_CALUCULATION;
}

/* 計算関数 */
void DataBase::Caluculation()
{
    /* 右回り時、配列の最後から最初まで通るとき(例28〜3など) */
    if (m_end_station - m_start_station < 0)
    {
        /* 終わりの駅〜配列の最後の駅までの合計を出す */
        for (int i = m_end_station; i < STATION_NUM; i++)
        {
            m_right_total_value += m_station_info[i].Spin;    //次の駅まで掛かる時間を合計値に足す
        }
        /* 配列の最初の駅〜始まりの駅までの合計を出す */
        for (int i = START_STATION; i < m_start_station; i++)
        {
            m_right_total_value += m_station_info[i].Spin;    //次の駅まで掛かる時間を合計値に足す
        }
    }

    /* 右回り時 */
    for (int i = m_start_station; i < m_end_station; i++)
    {
        m_right_total_value += m_station_info[i].Spin;
    }


    /* 左回り時、配列の最初から最後まで通るとき(例3〜28など) */
    if (m_end_station - m_start_station > 0)
    {
        /* 終わりの駅〜配列の最後の駅までの合計を出す */
        for (int i = STATION_NUM; i > m_end_station; i--)
        {
            m_left_total_value += m_station_info[i].Spin;   //次の駅まで掛かる時間を合計値に足す
        }

        /* 配列の最初の駅〜始まりの駅までの合計を出す */
        for (int i = m_start_station; i > START_STATION; i--)
        {
            m_left_total_value += m_station_info[i].Spin;   //次の駅まで掛かる時間を合計値に足す
        }
    }

    /*　左回り時 */
    for (int i = m_end_station; i < m_start_station; i--)
    {
        m_left_total_value += m_station_info[i].Spin;
    }
    m_step = STEP_SET;

}

/* 値わたし関数 */
void DataBase::SetTotalValue()
{
    g_drawer.SetRightTotalValue(m_right_total_value, m_left_total_value);
}


