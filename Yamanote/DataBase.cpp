#include "DataBase.h"
#include "Typedef.h"
#include <iostream>

/* 駅情報初期化 */
StationInfo m_station_info[STATION_NUM] =
{
    /* 駅名(最初は時計回り(配列で言うと0～28)で初期化、
       反時計回りは配列で言うと28～0になっている) */

    //駅名       移動時間
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

/* ステップ処理関数 */
void DataBase::StepChange()
{
    switch (m_step)
    {
    case DataBase::STEP_INPUT:            //入力情報参照
        Init();
    case DataBase::STEP_CALUCULATION:     //計算処理
        Caluculation();
    case DataBase::STEP_SET:              //計算結果保存処理
        SetTotalValue();
    default:
        break;
    }
}

/* 入力情報参照関数 */
void DataBase::Init()
{   
    m_left_total_value = 0;   //反時計回り合計時間初期化
    m_right_total_value = 0;  //時計回り合計時間初期化

    /* 入力した名前を保存 */
    strcpy_s(input_start_station, g_inputter.GetStartStationName());
    strcpy_s(input_end_station, g_inputter.GetEndStationName());

    /* 駅名検索 */
    SearchName(); 

    /* 次のステップへ */
    m_step = STEP_CALUCULATION;
}

/* 計算関数 */
void DataBase::Caluculation()
{
    RoteValue(m_start_station, m_end_station);  //移動時間

    m_step = STEP_SET;
}

/* 駅名検索関数 */
void DataBase::SearchName()
{
    /* 始まりの駅名が同じ要素数を保存 */
    for (int i = 0; i < STATION_NUM; i++)
    {
        if (strcmp(g_inputter.GetStartStationName(), m_station_info[i].station) == 0)
        {
            m_start_station = i;       //始まり
            g_drawer.NoneName(false);  //駅名無しフラグfalse
            break;
        }
        /* 駅名が合わなかった場合 */
        else
        {
            g_drawer.NoneName(true);   //駅名無しフラグtrue
        }
    }

    /* 終わりの駅名が同じ要素数を保存 */
    for (int i = 0; i < STATION_NUM; i++)
    {
        if (strcmp(g_inputter.GetEndStationName(), m_station_info[i].station) == 0)
        {
            m_end_station = i;         //終わり
            g_drawer.NoneName(false);  //駅名無しフラグfalse
            break;
        }
        /* 駅名が合わなかった場合 */
        else
        {
            g_drawer.NoneName(true);   //駅名無しフラグtrue
        }
    }
}


/* 移動時間計算 */ 
void DataBase::RoteValue(__int8 start_, __int8 end_)
{
    /* 右回り時(配列の要素内でループが回せるとき) */
    if (end_ - start_ > 0)
    {
        for (int i = start_; i < end_; i++)
        {
            m_right_total_value += m_station_info[i].Spin;
        }
      
    }
    /* 右回り時、配列の最後から最初まで通るとき(例:神田～東京[28]～[0]など) */
    else
    {
        /* 終わりの駅～配列の最後の駅までの合計を出す */
        for (int i = start_; i <= STATION_NUM; i++)
        {
            m_right_total_value += m_station_info[i].Spin;    //次の駅まで掛かる時間を合計値に足す
        }
        /* 配列の最初の駅～始まりの駅までの合計を出す */
        for (int i = START_STATION; i < end_; i++)
        {
            m_right_total_value += m_station_info[i].Spin;    //次の駅まで掛かる時間を合計値に足す
        }
    }


    /* 左回り時(配列の要素内でループが回せるとき) */
    if (end_ - start_ < 0)
    {
        /*　左回り時(配列を時計回りで初期化しているため反時計回り時は降りる駅の人駅前の時間を入れてやる) */
        for (int i = start_ - 1; i >= end_; i--)
        {
            m_left_total_value += m_station_info[i].Spin;
        }
    }
    /* 左回り時、配列の最初から最後まで通るとき(例:東京～神田[0]～[28]など) */
    else
    { 
        /* 配列の最初の駅～始まりの駅までの合計を出す */
        for (int i = start_; i > START_STATION; i--)
        {
            m_left_total_value += m_station_info[i].Spin;   //次の駅まで掛かる時間を合計値に足す
        }
        /* 終わりの駅～配列の最後の駅までの合計を出す */
        for (int i = STATION_NUM; i >= end_; i--)
        {
            m_left_total_value += m_station_info[i].Spin;   //次の駅まで掛かる時間を合計値に足す
        }
    }
}


/* 値渡し関数 */
void DataBase::SetTotalValue()
{
    g_drawer.SetRightTotalValue(m_right_total_value, m_left_total_value);

    m_step = STEP_INPUT;
}


