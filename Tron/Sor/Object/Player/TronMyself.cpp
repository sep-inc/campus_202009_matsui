#include "TronMyself.h"
#include "../../Entity.h"

//!初期化関数
void TornMyself::Init()
{
	m_stage = g_game_controller.GetStagePoint();  //!ステージクラスのアドレス代入
	m_pos = Vec(2, 5);       //!座標
	m_direction = Vec(0, 0); //!移動方向ベクトル
	m_player_type = MYSELF;  //!自分のプレイヤータイプ
	m_draw_font = "■";      //!描画スタイル
	m_deth = false;          //!死亡フラグ
	m_move = false;          //!移動フラグ

	//!ステージクラスに情報を送る
	m_stage->SetUpStageBuffer(m_pos, m_player_type);
}

//!移動方向選択関数
void TornMyself::SelectDirection()
{
	m_direction = g_inputter.InpuMoveKey();   //!十字キー入力

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
