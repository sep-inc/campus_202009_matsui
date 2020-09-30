#include "Second.h"
#include "../Definition.h"
#include "../Entity.h"
#include <stdio.h>
#include <string.h>

//!初期化
void Second::Init()
{
	//!座標
	m_piece_info.m_ou_pos = Vec(1, 0);   //!玉
	m_piece_info.m_kei_pos = Vec(3, 0);	 //!軽
	m_piece_info.m_kin_pos = Vec(0, 0);	 //!筋

	//!表示
	m_piece_info.m_ou_display = true;    //!玉 
	m_piece_info.m_kei_display = true;	 //!軽
	m_piece_info.m_kin_display = true;	 //!筋

	//!ふ
	for (int i = 0; i < HU_NUM; i++)
	{
		m_piece_info.m_hu_pos[i] = Vec(i, 1); 
		m_piece_info.m_hu_display[i] = true;
	}

	m_delete_pos = Vec(-1, -1);   //!消去座標を何もない場所に初期化

	m_player = SECOND_PLAYER;     //!プレイヤー番号

}

void Second::InitMove()
{
	//!玉 
	__int8 ou_move[OU_MOVE_MAX_Y][OU_MOVE_MAX_X] =
	{
		1,1,1,
		1,0,1,
		1,1,1
	};

	//!軽
	__int8 kei_move[KEIMA_MOVE_MAX_Y][KEIMA_MOVE_MAX_X] =
	{
		0,0,0,
		0,0,0,
		1,0,1
	};

	//!筋
	__int8 kin_move[KIN_MOVE_MAX_Y][KIN_MOVE_MAX_X] =
	{
		0,1,0,
		1,0,1,
		1,1,1
	};

	//!ふ
	__int8 hu_move[HU_MOVE_MAX_Y][HU_MOVE_MAX_X] =
	{
		0,
		1,
	};

	//!メンバ変数にコピー
	memcpy(m_piece_info.m_ou_move, ou_move, sizeof(ou_move));
	memcpy(m_piece_info.m_kei_move, kei_move, sizeof(kei_move));
	memcpy(m_piece_info.m_kin_move, kin_move, sizeof(kin_move));
	memcpy(m_piece_info.m_hu_move, hu_move, sizeof(hu_move));

	//!基準座標初期化
	m_piece_info.m_ou_move_center = Vec(1, 1);
	m_piece_info.m_kei_move_center = Vec(1, 0);
	m_piece_info.m_kin_move_center = Vec(1, 1);
	m_piece_info.m_hu_move_center = Vec(0, 0);
}

//!描画配列代入関数
void Second::SetUpDrawBuffer()
{
	g_drawer.SetUpBuffer(m_piece_info.m_ou_pos, "玉", m_piece_info.m_ou_display);
	g_drawer.SetUpBuffer(m_piece_info.m_kei_pos, "軽", m_piece_info.m_kei_display);
	g_drawer.SetUpBuffer(m_piece_info.m_kin_pos, "筋", m_piece_info.m_kin_display);

	for (int i = 0; i < HU_NUM; i++)
	{
		g_drawer.SetUpBuffer(m_piece_info.m_hu_pos[i], "ふ", m_piece_info.m_hu_display[i]);
	}
}

