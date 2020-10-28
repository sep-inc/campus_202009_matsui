#include "TronMyself.h"
#include "../../../../System/Inputter.h"
#include <stdio.h>

//!コンストラクタ(初期化が共通でないものを初期化)
TornMyself::TornMyself()
{
	m_player_type = TRON_MYSELF;  //!自分のプレイヤータイプ
	m_draw_font = "■";      //!描画スタイル
}

//!移動方向選択関数
void TornMyself::SelectDirection()
{
	printf("十字キーで移動\n");

	m_direction = Inputter::Instance()->InpuMoveKey();   //!十字キー入力

	//!移動方向が決まっている場合
	if (m_direction.x != 0 || m_direction.y != 0)
	{
		m_move = true;  //!移動フラグtrue

		//!何かに当たっている場合
		if (Collision() == true)
		{
			m_deth = true;  //!死亡フラグtrue
		}
	}
	else
	{
		m_move = false;
	}


}
