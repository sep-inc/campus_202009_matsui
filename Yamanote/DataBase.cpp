#include "DataBase.h"
#include "Typedef.h"
#include <iostream>

/* 駅情報初期化 */
StationInfo m_station_info[STATION_NUM] =
{
    /* 駅名(最初は時計回り(配列で言うと0～28)で初期化、
       反時計回りは配列で言うと28～0になっている) */

    //駅名       移動時間
    {"神田"    ,   1},
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
    {"秋葉原"  ,   2}
};

/* ステップ処理関数 */
void DataBase::StepChange()
{
    Input();            //入力情報参照
       
    Caluculation();     //入力情報参照
      
    SetTotalValue();    //計算結果保存処理
}

/* 入力情報参照関数 */
void DataBase::Input()
{   
    m_rotevalue.m_left_total_value = 0;   //反時計回り合計時間初期化
    m_rotevalue.m_right_total_value = 0;  //時計回り合計時間初期化

    /* 入力した名前を保存 */
    strcpy_s(input_start_station, g_inputter.GetStartStationName());
    strcpy_s(input_end_station, g_inputter.GetEndStationName());

    /* 駅名検索 */
    SearchName(); 
}

/* 計算関数 */
void DataBase::Caluculation()
{

    m_rotevalue.m_right_total_value = RightRoteValue(m_start_station, m_end_station);   //時計回り合計値
    m_rotevalue.m_left_total_value = LeftRoteValue(m_start_station, m_end_station);     //反時計回り合計値

    m_rotevalue. m_total_first_value = Comparison();                                    //中央線の最短時間
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

/* 移動時間計算(時計回り) */
__int8 DataBase::RightRoteValue(__int8 start_, __int8 end_)
{

    __int8 right_total_value = 0;

    /* 時計回り時(配列の要素内でループが回せるとき) */
    if (end_ - start_ > 0)
    {
        for (int i = start_; i < end_; i++)
        {
            right_total_value += m_station_info[i].Spin;
        }

    }
    /* 時計回り時、配列の最後から最初まで通るとき(例:神田～東京[28]～[0]など) */
    else
    {
        /* 終わりの駅～配列の最後の駅までの合計を出す */
        for (int i = start_; i <= STATION_NUM; i++)
        {
            right_total_value += m_station_info[i].Spin;    //次の駅まで掛かる時間を合計値に足す
        }
        /* 配列の最初の駅～始まりの駅までの合計を出す */
        for (int i = START_STATION; i < end_; i++)
        {
            right_total_value += m_station_info[i].Spin;    //次の駅まで掛かる時間を合計値に足す
        }
    }

    return right_total_value;
}

/* 移動時間計算(反時計回り) */
__int8 DataBase::LeftRoteValue(__int8 start_, __int8 end_)
{
    __int8 left_total_value = 0;

    /* 反時計回り時(配列の要素内でループが回せるとき) */
    if (end_ - start_ < 0)
    {
        /*　左回り時(配列を時計回りで初期化しているため反時計回り時は降りる駅の人駅前の時間を入れてやる) */
        for (int i = start_ - 1; i >= end_; i--)
        {
            left_total_value += m_station_info[i].Spin;
        }
    }
    /* 反時計回り時、配列の最初から最後まで通るとき(例:東京～神田[0]～[28]など) */
    else
    {
        /* 配列の最初の駅～始まりの駅までの合計を出す */
        for (int i = START_STATION; i < start_; i++)
        {
            left_total_value += m_station_info[i].Spin;   //次の駅まで掛かる時間を合計値に足す
        }
        /* 終わりの駅～配列の最後の駅までの合計を出す */
        for (int i = end_; i <= STATION_NUM; i++)
        {
            left_total_value += m_station_info[i].Spin;   //次の駅まで掛かる時間を合計値に足す
        }
    }
    return left_total_value;
}

/* 移動時間計算(中央線あり) */
__int8 DataBase::CenterLaneRoteValue(__int8 station_)
{
    __int8 right = 0;  //時計回り合計値
    __int8 left = 0;   //反時計回り合計値

    /* 指定駅が神田(配列[0])より時計回りで後にあるとき && 指定駅が新宿(配列[13])より時計回りで前にあるとき*/
    if (station_ >= CENTER_START_STATION && station_ <= CENTER_END_STATION)
    {
        //時計回り
        for (int i = station_; i < CENTER_END_STATION; i++)
        {
            right += m_station_info[i].Spin;    //station_～中央線までの時計回り合計値
        }
        //反時計回り
        for (int i = START_STATION; i < station_; i++)
        {
            left += m_station_info[i].Spin;     //station_～中央線までの反時計回り合計値
        }
    }
    /* 指定駅が神田(配列[0])より時計回りで後にあるとき && 指定駅が新宿(配列[13])より時計回りで後にあるとき*/
    else if (station_ >= CENTER_START_STATION && station_ >= CENTER_END_STATION)
    {
        //時計回り
        for (int i = station_; i < STATION_NUM; i++)
        {
            right += m_station_info[i].Spin;    //station_～中央線までの時計回り合計値
        }
        //反時計回り
        for (int i = CENTER_END_STATION; i < station_; i++)
        {
            left += m_station_info[i].Spin;     //station_～中央線までの反時計回り合計値
        }
    }

    /* 時間が短いほうを返す */
    if (left < right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

/* 最短時間比較 */
__int8 DataBase::Comparison()
{
    __int8 m_first_start_center = CenterLaneRoteValue(m_start_station);   //乗る駅から中央線までの最短時間
    __int8 m_first_end_center = CenterLaneRoteValue(m_end_station);       //降りる駅から中央線までの最短時間

    __int8 m_total_center = m_first_start_center + m_first_end_center + CENTER_LANE_TIME;   //中央線を使った最短時間


    /* 山手線のみの時計回り、反時計回りの最短時間を比較 */
    if (m_rotevalue.m_right_total_value < m_rotevalue.m_left_total_value)
    {
        m_rotevalue.m_total_first_yamanote = m_rotevalue.m_right_total_value;    //時計回り合計時間
    }
    else
    {
        m_rotevalue.m_total_first_yamanote = m_rotevalue.m_left_total_value;    //反時計回り合計時間
    }


    /* 最終的に山手線のみの最短時間と中央線ありの最短時間を比較 */
    if (m_rotevalue.m_total_first_yamanote < m_total_center)
    {
        return m_rotevalue.m_total_first_yamanote;   //山手線のみ
    }
    else
    {
        return m_total_center;   //中央線あり
    }
}


/* 値渡し関数 */
void DataBase::SetTotalValue()
{
    /* 時計回り、反時計回り合計時間を返す */
    g_drawer.SetRightTotalValue(m_rotevalue.m_right_total_value, m_rotevalue.m_left_total_value);

    /* 最短時間時間を返す */
    g_drawer.SetFirstTime(m_rotevalue.m_total_first_value);
}


