#include "Disk.h"
#include "../Typedef.h"

/* 初期化 */
void Disk::Init(Vec pos_, unsigned  __int8 width_, unsigned  __int8 height_)
{
	ObjectBase::Init(pos_, width_, height_);
}

/* 描画座標を代入 */
void Disk::SetUpBuffer()
{
	g_drawer.SetUpBuffer(m_pos, m_width, m_height, OBJECT_TYPE::DISK);
}

/* 駒座標変更関数 */
void Disk::SetPos(unsigned __int8 number_, unsigned __int8 width_)
{
    /*  一度左端のBoxに座標をリセットする */
    switch (width_)
    {
    case 1:
        m_pos.x = 3;   //小サイズ
        break;
    case 3:
        m_pos.x = 2;   //中サイズ
        break;
    case 5:
        m_pos.x = 1;   //大サイズ
        break;
    default:
        break;
    }

    switch (number_)
    {
    case 1:
        m_pos.x += 0;   //1番目の箱を選んだ時
        break;
    case 2:
        m_pos.x += 6;   //2番目の箱を選んだ時
        break;
    case 3:
        m_pos.x += 12;  //3番目の箱を選んだ時
        break;
    default:
        break;
    }

    m_pos.y = g_boxarray.SetDiskPos_Y();
}

