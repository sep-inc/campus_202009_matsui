#include "Piece.h"
#include "../Entity.h"
#include "../World.h"
#include "Player.h"
#include "Enemy.h"

#include <random>

//!ステップ処理関数
void Piece::StepChange()
{
	switch (m_step)
	{
	case Piece::STEP_INIT:     //!初期化
		Init();
		break;
	case Piece::STEP_PLAYER:   //!プレイヤーのターン
		Put();
		break;
	case Piece::STEP_ENEMY:    //!敵のターン
		Put();
		break;
	default:
		break;
	}
}

//!初期化関数
void Piece::Init()
{
	m_player = new Player;
	m_enemy = new Enemy;

	m_player->Init();   //!プレイヤー
	m_enemy->Init();    //!敵

	m_step = STEP_PLAYER;
}

//!描画座標代入関数
void Piece::SetUpDrawBuffer()
{
	m_player->SetUpDrawBuffer();   //!プレイヤー
	m_enemy->SetUpDrawBuffer();	   //!敵
}

//!配置関数
void Piece::Put()
{
	switch (m_step)
	{
	case Piece::STEP_PLAYER:   //!プレイヤー
		m_player->Put();
		m_step = STEP_ENEMY;  //!配置権を敵に
		break;
	case Piece::STEP_ENEMY:   //!敵
		m_enemy->Put();
		m_step = STEP_PLAYER; //!配置権をプレイヤーに
		break;
	default:
		break;
	}
}

//!解放関数
void Piece::Delete()
{
	delete m_player;
	delete m_enemy;
}

//!コンティニュー関数
void Piece::Continue()
{
	m_step = STEP_INIT;  //!初期化ステップへ
}
