#include "PacManEnemy.h"
#include "AI/ChaseAI.h"
#include <stdlib.h>
#include <string.h>

const __int16 PacManEnemy::m_move_maxcount = 30; //!移動までに掛かる時間

//!コンストラクタ
PacManEnemy::PacManEnemy()
{
	m_ai = nullptr;
}

//!デストラクタ
PacManEnemy::~PacManEnemy()
{
	m_ai->DeleteAI();
}

//!共通外変数初期化関数
void PacManEnemy::InitAnother()
{
	
	if (m_ai == nullptr) { m_ai = new AIController(m_stage); }  //!AIインスタンス化

	m_player_type = ENEMY;   //!自分のオブジェクトタイプ
	m_draw_font = "＠";		 //!描画文字

	m_move_counter = 0;      //!移動時間加算用
	m_move_speed = 1;        //!移動速度

	RandCreate();            //!座標初期化

	m_sorce_pos = m_pos;     //!移動前座標
}

//!更新処理
void PacManEnemy::Update()
{
	m_move_counter += m_move_speed;  //!移動までの時間をカウント

    //!移動カウントが指定時間を満たしたら
	if (m_move_counter >= m_move_maxcount)
	{
		m_ai->ChangeAI(m_pos);

		//!移動方向選択
		SelectDirection();

		//!移動
		Move();

		//!ステージ情報更新
		m_stage->SetUpStageBuffer(m_sorce_pos, m_pos, m_player_type);

		m_move_counter = 0;
	}
}

//!乱数座標初期化関数
void PacManEnemy::RandCreate()
{
	//!配置条件を満たすまで回す
	while (true)
	{
		m_pos.x = rand() % GAME_WIDTH;   //!座標指定 
		m_pos.y = rand() % GAME_HEIGHT;	 //!座標指定

		//!指定座標箇所が壁であるかどうか
		if (m_stage->SearchObject(m_pos) != WALL)
		{
			//!生成間隔範囲内に他のアイテム、プレイヤー、敵がいるかどうか
			if (SearchRange(m_pos) == false)
			{
				//!配置できるならステージに情報を送る
				m_stage->SetUpStageBuffer(m_pos, m_pos, ENEMY);
				break;
			}
		}
	}
}

//!自分の周り調査関数
bool PacManEnemy::SearchRange(Vec pos_)
{
	Vec range;  //!調査座標

	//!生成間隔範囲調査
	for (int y = 0; y < ENEMY_RANGE_Y; y++)
	{
		for (int x = 0; x < ENEMY_RANGE_X; x++)
		{
			range.x = pos_.x - RANGE_CENTER_X + x;  //!敵座標を中心として範囲の左上を指定
			range.y = pos_.y - RANGE_CENTER_Y + y;  //!敵座標を中心として範囲の左上を指定

			//!ステージ範囲内の座標の場合のみ調べる
			if (range.x > 0 && range.x < GAME_WIDTH &&
				range.y > 0 && range.y < GAME_HEIGHT)
			{
				//!指定箇所に壁以外何かある場合
				if (m_stage->SearchObject(range) != WALL &&
					m_stage->SearchObject(range) != NONE)
				{
					return true;
				}
			}
		}
	}

	return false;
}

//!移動関数
void PacManEnemy::Move()
{
	//!追跡中
	if (m_ai->ChaseMode() == true)
	{
		m_move_speed = 3;  //!スピードを上げる
	}
	//!追跡外
	else
	{
		m_move_speed = 1;  //!初期スピードにする
	}

	//!移動
	m_pos.x += m_direction.x;
	m_pos.y += m_direction.y;
}

//!移動方向選択関数
void PacManEnemy::SelectDirection()
{
	m_sorce_pos = m_pos;  //!移動前の座標保存

	m_direction = m_ai->GetDirection(); //!移動方向をAIで決める
	
}
