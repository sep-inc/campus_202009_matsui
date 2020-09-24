#include "Piece.h"
#include "../Entity.h"
#include "../World.h"
#include <random>

//!ステップ処理関数
void Piece::StepChange()
{
	switch (m_step)
	{
	case Piece::STEP_INIT:
		Init();
		break;
	case Piece::STEP_PUT:
		Put();
		break;
	default:
		break;
	}
}

//!初期化関数
void Piece::Init()
{
	//!座標の初期値は表示されても見えない位置にする
	m_player_pos = Vec(-5, -5); 
	m_enemy_pos = Vec(-5, -5);   

	//!0～2の乱数で初期化
	m_randm_number.x = rand() % BORD_SIZE;
	m_randm_number.y = rand() % BORD_SIZE;

	m_step = STEP_PUT;
}

//!描画座標代入関数
void Piece::SetUpDrawBuffer()
{
	g_drawer.SetUpBuffer(m_player_pos, "●");
	g_drawer.SetUpBuffer(m_enemy_pos, "×");
}

//!移動関数まとめ
void Piece::Put()
{
	//!プレイヤーの配置
	PlayerPut();
	g_bord.SetPiecePos(m_player_pos, OBJECT_TYPE::PLAYER_PIECE);
	
	//!敵の配置
	EnemyPut();
	if (g_bord.SearchNumber() == true)
	{
		g_bord.SetPiecePos(m_enemy_pos, OBJECT_TYPE::ENEMY_PIECE);
	}	
}

//!プレイヤー配置関数
void Piece::PlayerPut()
{
	//!選択した場所が置けるかどうか調べる
	if (g_bord.PutSearch(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber()) == true)
	{
		m_player_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());
	}
	//!置けない場合はもう一度選択
	else 
	{
		while (g_bord.PutSearch(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber()) == false)
		{
			g_inputter.InputNumber();
		}
		m_player_pos = Vec(g_inputter.GetSelectFont(), g_inputter.GetSelectNumber());
	}
}

//!敵配置関数
void Piece::EnemyPut()
{
	//!乱数で出した位置が置けるか。また、配置できる場所があるかどうか調べる
	while (g_bord.PutSearch(m_randm_number.x, m_randm_number.y) == false
		&& g_bord.SearchNumber() == true)
	{
		m_randm_number.x = rand() % BORD_SIZE;
		m_randm_number.y = rand() % BORD_SIZE;
	}

	m_enemy_pos = Vec(m_randm_number.x, m_randm_number.y);
}
