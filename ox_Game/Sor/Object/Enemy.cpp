#include "Enemy.h"
#include "../Entity.h"
#include "../World.h"
#include <random>

//!初期化関数
void Enemy::Init()
{
	m_pos = Vec(-5, -5);  //!表示されないよう見えない位置に初期化

	//!0～2の乱数で初期化
	m_randm_number.x = rand() % BORD_SIZE;
	m_randm_number.y = rand() % BORD_SIZE;
}

//!描画座標代入関数
void Enemy::SetUpDrawBuffer()
{
	g_drawer.SetUpBuffer(m_pos, "×");
}

//!配置
void Enemy::Put()
{
	//!乱数で出した位置が置けるか。また、配置できる場所があるかどうか調べる
	while (g_bord.PutSearch(m_randm_number.x, m_randm_number.y) == false
		&& g_bord.SearchNumber() == true)
	{
		//!配置できない場合もう一度乱数を出す
		m_randm_number.x = rand() % BORD_SIZE;   
		m_randm_number.y = rand() % BORD_SIZE;
	}

	m_pos = Vec(m_randm_number.x, m_randm_number.y);   //座標更新

	//!配置場所があった場合
	if (g_bord.SearchNumber() == true)
	{
		g_bord.SetPiecePos(m_pos, OBJECT_TYPE::ENEMY_PIECE);   //盤配列に座標代入
	}
}
