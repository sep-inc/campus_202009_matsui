#include "Player.h"
#include "../Entity.h"
#include "../World.h"

//!初期化関数
void Player::Init()
{
	m_pos = Vec(-5, -5);  //!表示されないよう見えない位置に初期化
}

//!描画座標代入関数
void Player::SetUpDrawBuffer()
{
	g_drawer.SetUpBuffer(m_pos, "●");
}

//!配置
void Player::Put()
{
	g_inputter.InputNumber();    //!配置場所入力

	//!選択した場所が置けるかどうか調べる
	if (g_bord.PutSearch(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber()) == true)
	{
		m_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //座標更新
	}
	//!置けない場合はもう一度選択
	else
	{
		while (g_bord.PutSearch(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber()) == false)
		{
			g_inputter.InputNumber();    //!配置場所再入力
		}

		m_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());  //座標更新
	}

	g_bord.SetPiecePos(m_pos, OBJECT_TYPE::PLAYER_PIECE);   //盤配列に座標代入
}
