#include "HanoiTowerDiskArray.h"
#include "../../../System/Inputter.h"
#include <stdlib.h>
#include <stdio.h>

/* 初期化 */
void HanoiTowerDiskArray::Init(HanoiTowerBoxArray* boxarray_)
{
	Vec2 pos = Vec2(3, 2);  //最初は一番上に置いてある円盤の座標(左上を基点として)で初期化

	__int8 width = SMALL_DISK_WIDTH;   //最初は一番上に置いてある円盤のWidthで初期化

	/* 円盤の数分回す */
	for (int i = 0; i < DISK_NUM; i++)
	{
		m_disk[i].Init(pos, width, DISK_HEIGHT);

		pos.x--;  //左上を基点とした場合x座標は大きくなるにつれ広くなるため
		pos.y++;  //下に積んであるため

		if (i == 0)
		{
			width = NOMAL_DISK_WIDTH;  //普通サイズ
		}
		else if (i == 1)
		{
			width = BIG_DISK_WIDTH;   //大サイズ
		}
	}

	m_start_number = 0;
	m_end_number = 0;

	/* 調査用配列に代入 */
	SetUpBox(boxarray_);
}

/* 移動処理 */
void HanoiTowerDiskArray::Move(HanoiTowerBoxArray* boxarray_)
{
	//m_start_number = Inputter::Instance()->ReInputNumber();

	/*for (int num = 0; num < DISK_NUM; num++)
	{
		if (boxarray_->SearchSorceDiskSize(m_disk[num].GetWidth(), m_start_number)==true)
		{
			m_end_number = Inputter::Instance()->ReInputNumber();

			if (boxarray_->SearchSorceDiskSize(m_disk[num].GetWidth(), m_start_number) == true)
			{

			}
		}
	}*/

	Inputter::Instance()->InputNumber();

	for (int num = 0; num < DISK_NUM; num++)
	{
		/* 動かす円盤が箱を調べた円盤と同じサイ^ズ(一番上に円盤がある)なら動かす */
		if (boxarray_->SearchMoveDiskSize(m_disk[num].GetWidth(), Inputter::Instance()->GetStartNumber(), Inputter::Instance()->GetEndNumber()) == true)
		{
			/* 座標更新 */
			m_disk[num].SetPos(Inputter::Instance()->GetEndNumber(), m_disk[num].GetWidth(), boxarray_);
			boxarray_->ClearBoxBuffer();
			break;
		}
	}
	system("cls");

	SetUpBox(boxarray_);

}

/* 描画座標更新 */
void HanoiTowerDiskArray::SetUpDrawBuffer()
{
	for (int i = 0; i < DISK_NUM; i++)
	{
		m_disk[i].SetUpBuffer();
	}
}

/* 調査用配列に円盤を代入 */
void HanoiTowerDiskArray::SetUpBox(HanoiTowerBoxArray* boxarray_)
{
	for (int i = 0; i < DISK_NUM; i++)
	{
		boxarray_->SetUpDisk(m_disk[i].GetPos(), m_disk[i].GetWidth(), DISK_HEIGHT);
	}
}
