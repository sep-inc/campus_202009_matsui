#include "DiskArray.h"
#include "../Typedef.h"

/* ステップ処理 */
void DiskArray::StepChange()
{
	switch (m_step)
	{
	case DiskArray::STEP_INIT:    //初期化
		Init();
		break;
	case DiskArray::STEP_MOVE:    //移動
		Move();
		break;
	default:
		break;
	}
}

/* 初期化 */
void DiskArray::Init()
{
	Vec pos = Vec(3,2);  //最初は一番上に置いてある円盤の座標(左上を基点として)で初期化

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

	/* 調査用配列に代入 */
	SetUpBox();

	/* 次のステップへ */
	m_step = STEP_MOVE;
}

/* 移動処理 */
void DiskArray::Move()
{

	for (int num = 0; num < DISK_NUM; num++)
	{
		/* 動かす円盤が箱を調べた円盤と同じサイ^ズ(一番上に円盤がある)なら動かす */
		if (g_boxarray.SearchMoveDiskSize(m_disk[num].GetWidth(), g_inputter.GetStartNumber(), g_inputter.GetEndNumber()) == true)
		{
			/* 座標更新 */
			m_disk[num].SetPos(g_inputter.GetEndNumber(), m_disk[num].GetWidth());
			g_boxarray.ClearBoxBuffer();
			break;
		}
	}

	SetUpBox();

}

/* 描画座標更新 */
void DiskArray::SetUpDrawBuffer()
{
	for (int i = 0; i < DISK_NUM; i++)
	{
		m_disk[i].SetUpBuffer();
	}
}

/* 調査用配列に円盤を代入 */
void DiskArray::SetUpBox()
{
	for (int i = 0; i < DISK_NUM; i++)
	{
		g_boxarray.SetUpDisk(m_disk[i].GetPos(), m_disk[i].GetWidth(), DISK_HEIGHT);
	}
}
