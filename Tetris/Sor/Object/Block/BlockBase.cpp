#include "BlockBase.h"
#include "../../Entity.h"

//!コンストラクタ
Tetris_BlockBase::Tetris_BlockBase(Tetris_Stage* stage_) :
	m_stage(stage_),   //!ステージアドレス
	m_font("■"),      //!表示スタイル
	m_pos_x(3.0f), m_pos_y(-1.0f), m_next_pos_x(m_pos_x), m_next_pos_y(m_pos_y),   //!座標
	m_speed(0.03f),     //!落下速度
	m_stop(false),      //!停止フラグ
	m_angle_type(0),    //!現在角度保存用
	m_counter(0),
	m_play(false)
{
}

//!初期化関数(繰り返し)
void Tetris_BlockBase::Reset()
{
	m_pos_x = 2.0f;  //!座標
	m_pos_y = -1.0f;	 //!座標

	m_next_pos_x = m_pos_x; //!移動後座標
	m_next_pos_y = m_pos_y; //!移動後座標 

	m_angle_type = 0;

	m_stop = false;  //!停止フラグ
}

//!更新関数
void Tetris_BlockBase::Update()
{
	Move();
	PlayMove();
	SetStageBuffer();
}

//!移動関数
void Tetris_BlockBase::Move()
{
	//!何かに乗っていない場合
	if (m_play != true)
	{
		m_next_pos_y += m_speed;    //!落下
	}

	
	//!床、もしくは固定されたブロックに当たった場合
	if (Collision() == true)
	{
		m_next_pos_y -= m_speed; //!遊びの時間の間動けるように座標を戻す
		m_play = true;  //!遊び判定true
	}
	else
	{
		m_pos_x = m_next_pos_x;   //!現在位置を移動後に変更
		m_pos_y = m_next_pos_y;   //!現在位置を移動後に変更
	}
}

//!遊び時間関数
void Tetris_BlockBase::PlayMove()
{
	//!何かの上に乗った場合
	if (m_play == true)
	{
		m_counter++;

		//!少しの時間動けるようにする
		if (m_counter == 30)
		{
			m_next_pos_y += m_speed; //!時間が過ぎると落下

			//!落下時にもう一度何かの上にちゃんと乗っているか判定
			if (Collision() == true)
			{
				SetStageClearBuffer(); //!ステージに固定

				m_stop = true;     //!停止フラグtrue
			}
			
			m_play = false;
			m_counter = 0;
		}
	}
	
}

//!当たり判定関数
bool Tetris_BlockBase::Collision()
{
	//!型配列とステージ配列の差分を比較するよう
	__int8 value = 0;

	//!ブロック型配列の中身を渡す
	for (int y = m_block_min_array.y; y <= m_block_max_array.y; y++)
	{
		for (int x = m_block_min_array.x; x <= m_block_max_array.x; x++)
		{
			if (m_block[y][x] == 1)
			{
				//!型配列とステージ配列の差分を出す
				value = m_stage->SearchStage(Vec2((int)floor(m_next_pos_x + x), (int)floor(m_next_pos_y + y)));
			}

			//!ブロックが重なっていた(当たっていた)場合
			if (value == WALL || value == FIXED_BLOCK)
			{
				return true;
			}
		}
	}

	return false;
}

//!ステージ更新関数
void Tetris_BlockBase::SetStageBuffer()
{
	//!ブロック型配列の中身を渡す
	for (int y = m_block_min_array.y; y <= m_block_max_array.y; y++)
	{
		for (int x = m_block_min_array.x; x <= m_block_max_array.x; x++)
		{
			if (m_block[y][x] == 1)
			{
				m_stage->SetUpBlock(Vec2((int)floor(m_pos_x + x), (int)floor(m_pos_y + y)), BLOCK);
			}
		}
	}
}

//!ステージクリア配列更新関数
void Tetris_BlockBase::SetStageClearBuffer()
{
	//!ブロック型配列の中身を渡す
	for (int y = m_block_min_array.y; y <= m_block_max_array.y; y++)
	{
		for (int x = m_block_min_array.x; x <= m_block_max_array.x; x++)
		{
			if (m_block[y][x] == 1)
			{
				m_stage->SetUpStageClear(Vec2((int)floor(m_pos_x + x), (int)floor(m_pos_y + y)), FIXED_BLOCK);
			}
		}
	}
}

//!予測枠更新関数
void Tetris_BlockBase::SetNextBlockBuffer()
{
	//!ブロック型配列の中身を渡す
	for (int y = m_block_min_array.y; y <= m_block_max_array.y; y++)
	{
		for (int x = m_block_min_array.x; x <= m_block_max_array.x; x++)
		{
			if (m_block[y][x] == 1)
			{
				m_stage->SetUpNextBlock(Vec2(x, y), (OBJECT_TYPE)m_block[y][x]);
			}
		}
	}
}

//!ブロック描画情報代入関数
void Tetris_BlockBase::SetUpDrawBuffer(GAME_TYPE type_)
{
	__int8 wall = 1;

	//!ブロック型配列の中身を渡す
	for (int y = m_block_min_array.y; y <= m_block_max_array.y; y++)
	{
		for (int x = m_block_min_array.x; x <= m_block_max_array.x; x++)
		{
			if (m_block[y][x] == 1)
			{
				//!壁を除いた現在座標と形配列の中にある位置を足した座標を送る
				g_drawer.SetUpBuffer(Vec2((int)floor(m_pos_x + x + wall), (int)floor(m_pos_y + y + wall)), m_font, type_);
			}
		}
	}
	
}

//!使用ブロック座標更新関数
void Tetris_BlockBase::SetBlockPos(float x_, float y_)
{
	m_next_pos_x += x_;
	m_next_pos_y += y_;
}


//!固定箇所判定関数
bool Tetris_BlockBase::SearchFixedPos()
{
	//!型配列とステージ配列の差分を比較するよう
	__int8 value = 3;
	float m_next_pos_y_ = m_next_pos_y;   //!移動後Y座標(移動時に小数を使うためfloat)

	//!ステージの上から下へ調べる
	for (int y = 0; y <= GAME_HEIGHT; y++)
	{
		//!ブロック型配列の中身を渡す
		for (int y = m_block_min_array.y; y <= m_block_max_array.y; y++)
		{
			for (int x = m_block_min_array.x; x <= m_block_max_array.x; x++)
			{
				if (m_block[y][x] == 1)
				{
					//!型配列とステージ配列の差分を出す
					value = m_block[y + 1][x] - m_stage->SearchStage(Vec2((int)floor(m_pos_x + x), (int)floor(m_next_pos_y_ + y)));
				}

				//!ブロックが重なっていた(当たっていた)場合
				if (value <= 0)
				{
					return true;
				}
			}
		}
	}
	

	return false;
}
