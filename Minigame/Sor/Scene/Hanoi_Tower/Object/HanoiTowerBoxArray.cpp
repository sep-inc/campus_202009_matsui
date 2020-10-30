﻿#include "HanoiTowerBoxArray.h"
#include <string.h>

/* 初期化 */
void HanoiTowerBoxArray::Init()
{
    Vec2 pos = Vec2(1, 2); //左端の箱の座標で初期化

    for (int i = 0; i < HANOITOWER_BOX_NUM; i++)
    {
        m_box[i].Init(pos, HANOITOWER_BOX_WIDTH, HANOITOWER_BOX_HEIGHT);
        pos.x += HANOITOWER_BOX_WIDTH + 1; //Boxの横幅+1の感覚で配置する
    }

    ClearBoxBuffer();
}


/* 検索 */
void HanoiTowerBoxArray::Search()
{
    /* 終了判定 */
    if (SearchRightBox() == true)
    {
        m_end = true;
    }

}

/* 指定したboxの座標から中身を調べる */
unsigned __int8 HanoiTowerBoxArray::SearchBox(unsigned __int8 pos_x_)
{
    unsigned __int8 disk_size = 0;   //diskの横幅を返す用

    /* for文でm_box_bufferの中身を調べる(上の段から調べる) */
    for (int y = HANOITOWER_BUFFER_BOX_POS_Y; y < HANOITOWER_BOX_WIDTH; y++)
    {
        /* 指定したboxのx座標～ Boxの横幅 */
        for (int x = pos_x_; x < pos_x_ + HANOITOWER_BOX_WIDTH; x++)
        {
            if (m_box_buffer[y][x] == HANOITOWER_OBJECT_TYPE::DISK)
            {
                disk_size++;   //円盤の横幅を広げる
            }
        }

        /* diskの横幅が0以上なら(diskがあれば) */
        if (disk_size > 0)
        {
            return disk_size;   //移動元の円盤のサイズを返す
        }
    }

    /* diskがなければ一番下に置けるようにサイズをでかくして置けるようにする */
    return HANOITOWER_DISK_MAX_WIDTH;
}

/* 右端の箱にすべての円盤があるかどうか調べる処理 */
bool HanoiTowerBoxArray::SearchRightBox()
{
    m_disk_counter = 0;

    for (int y = HANOITOWER_BUFFER_BOX_POS_Y; y <= HANOITOWER_BUFFER_BOX_POS_Y + HANOITOWER_BOX_HEIGHT; y++)
    {
        /* x軸は箱の真ん中だけ知れればよいので固定 */
        if (m_box_buffer[y][15] == HANOITOWER_OBJECT_TYPE::DISK)
        {
            m_disk_counter++;
        }
    }

    /* 円盤がすべて右にあるときあるとき */
    if (m_disk_counter >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }

}

/* 移動するために箱の中身を調べる */
bool HanoiTowerBoxArray::SearchMoveDiskSize(unsigned __int8 disk_width, unsigned __int8 now_number_, unsigned __int8 next_number_)
{
    m_now_investigation_pos = SearchPos_X(now_number_);     //移動元の基準座標(左上)を代入  
    m_next_investigation_pos = SearchPos_X(next_number_);   //移動先の基準座標(左上)を代入    


    __int8 m_now_disk_size = 0;    //移動元のdiskの横幅保存用
    __int8 m_next_disk_size = 0;   //移動先のdiskの横幅保存用

    m_now_disk_size = SearchBox(m_now_investigation_pos);     //移動元boxの中身を調べる
    m_next_disk_size = SearchBox(m_next_investigation_pos);   //移動先boxの中身を調べる

    /* 移動元のdiskが存在、かつ移動先にdiskを置けるとき*/
    if (m_now_disk_size == disk_width && m_next_disk_size > disk_width)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 移動元にDiskがあるか調べる */
bool HanoiTowerBoxArray::SearchSorceDiskSize(unsigned __int8 disk_width, unsigned __int8 now_number_)
{
    m_now_investigation_pos = SearchPos_X(now_number_);     //移動元の基準座標(左上)を代入

    __int8 m_now_disk_size = 0;    //移動元のdiskの横幅保存用

    m_now_disk_size = SearchBox(m_now_investigation_pos);     //移動元boxの中身を調べる
   
    /* 移動元のdiskが存在、かつ移動先にdiskを置けるとき*/
    if (m_now_disk_size == disk_width)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 移動先にDiskがあるか調べる */
bool HanoiTowerBoxArray::SearchNextDiskSize(unsigned __int8 disk_width, unsigned __int8 next_number_)
{
    m_next_investigation_pos = SearchPos_X(next_number_);   //移動先の基準座標(左上)を代入    

    __int8 m_next_disk_size = 0;   //移動先のdiskの横幅保存用

    m_next_disk_size = SearchBox(m_next_investigation_pos);   //移動先boxの中身を調べる

    /* 移動元のdiskが存在、かつ移動先にdiskを置けるとき*/
    if (m_next_disk_size > disk_width)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 移動元の基準座標更新関数 */
unsigned __int8 HanoiTowerBoxArray::SearchPos_X(unsigned __int8 number_)
{
    unsigned __int8 investigation_pos = 0;   //調査用boxpos

    switch (number_)
    {
    case 1://1番の時
        investigation_pos = 1;   //箱の左端に設定
        break;
    case 2: //2番の時
        investigation_pos = 7;   //箱の左端に設定
        break;
    case 3: //3番の時
        investigation_pos = 13;  //箱の左端に設定
        break;
    default:
        break;
    }

    return investigation_pos;
}

/* 移動先のdiskの置けるy座標を検索 */
unsigned __int8 HanoiTowerBoxArray::SetDiskPos_Y()
{
    unsigned __int8 disk_size = 0;
    unsigned __int8 pos_y = 0;

    /* for文でm_box_bufferの中身を調べる(上の段から調べる) */
    for (int y = HANOITOWER_BUFFER_BOX_POS_Y; y < HANOITOWER_BOX_WIDTH; y++)
    {
        /* 移動先の座標～ Boxの横幅 */
        for (int x = m_next_investigation_pos; x < m_next_investigation_pos + 5; x++)
        {
            if (m_box_buffer[y][x] == HANOITOWER_OBJECT_TYPE::DISK)
            {
                disk_size++;   //diskのサイズ
            }
        }

        /* diskが見つかったら */
        if (disk_size > 0)
        {
            pos_y = y - 1;  //見つかったdiskの上に配置するため-1する
            return pos_y;
        }
        else
        {
            pos_y = y;      //見つからなければ一番下に配置
        }
    }

    return pos_y;
}

/* 円盤を調査用Box配列に代入 */
void HanoiTowerBoxArray::SetUpDisk(Vec2 pos, unsigned  __int8 width_, unsigned  __int8 height_)
{
    for (int i = 0; i < width_; i++)
    {
        m_box_buffer[pos.y][pos.x + i] = HANOITOWER_OBJECT_TYPE::DISK;
    }
}

/* 描画配列に代入 */
void HanoiTowerBoxArray::SetUpDrawBuffer()
{
    for (int i = 0; i < HANOITOWER_BOX_NUM; i++)
    {
        m_box[i].SetUpBuffer();
    }
}

/* 調査用Box配列初期化 */
void HanoiTowerBoxArray::ClearBoxBuffer()
{
    memset(&m_box_buffer, 0, sizeof(m_box_buffer));
}
