#include "Stage.h"
#include "../Entity.h"


//!コンストラクタ
Tetris_Stage::Tetris_Stage()
{
	memset(m_stage, NONE, sizeof(m_stage));   //!ステージ配列を空で初期化

	//!壁(不変的なもの)で初期化
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		m_stage[y][0].m_obj = WALL;
		m_stage[y][GAME_WIDTH - WALL_SIZE].m_obj = WALL;
	}
	for (int x = 0; x < GAME_WIDTH; x++)
	{
		m_stage[0][x].m_obj = WALL;
		m_stage[GAME_HEIGHT - WALL_SIZE][x].m_obj = WALL;
	
	}

	memset(m_next_block, NONE, sizeof(m_next_block));   //!予測枠を空で初期化

	//!壁(不変的なもの)で初期化
	for (int y = 0; y < NEXT_BLOCK_HEIGHT; y++)
	{
		m_next_block[y][0].m_obj = WALL;
		m_next_block[y][NEXT_BLOCK_HEIGHT - WALL_SIZE].m_obj = WALL;
	}
	for (int x = 0; x < NEXT_BLOCK_WIDTH; x++)
	{
		m_next_block[0][x].m_obj = WALL;
		m_next_block[NEXT_BLOCK_WIDTH - WALL_SIZE][x].m_obj = WALL;
	}

	memcpy(m_next_block_clear, m_next_block, sizeof(m_next_block));  //!予測枠クリア用配列に予測枠配列をコピー
}

void Tetris_Stage::Update()
{
	SearchDeleteBlock();
}

//!ステージ描画情報代入関数
void Tetris_Stage::SetUpDrawStageBuffer(GAME_TYPE type_)
{
	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		for (int x = 0; x < GAME_WIDTH; x++)
		{
			//!オブジェクトの種類
			switch (m_stage[y][x].m_obj)
			{
			case FIXED_BLOCK: //!固定されたブロック
				g_drawer.SetUpBuffer(Vec2(x, y), "■", type_);
				break;
			case WALL: //!壁
				g_drawer.SetUpBuffer(Vec2(x, y), "□", type_);
				break;
			case NONE: //!空
				g_drawer.SetUpBuffer(Vec2(x, y), "　", type_);
				break;
			default:
				break;
			}
		}
	}
}

//!予測枠描画情報代入関数
void Tetris_Stage::SetUpDrawBlockBuffer(GAME_TYPE type_)
{
	//!壁(不変的なもの)と空で初期化
	for (int y = 0; y < NEXT_BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < NEXT_BLOCK_WIDTH; x++)
		{
			//!オブジェクトの種類
			switch (m_next_block[y][x].m_obj)
			{
			case FIXED_BLOCK: //!固定されたブロック
				g_drawer.SetUpBuffer(Vec2(x + GAME_WIDTH + WALL_SIZE, y), "■", type_);
				break;
			case WALL: //!壁
				g_drawer.SetUpBuffer(Vec2(x + GAME_WIDTH + WALL_SIZE, y), "□", type_);
				break;
			case NONE: //!空
				g_drawer.SetUpBuffer(Vec2(x + GAME_WIDTH + WALL_SIZE, y), "　", type_);
				break;
			default:
				break;
			}
		}
	}
}

//!ブロック固定関数
void Tetris_Stage::SetUpBlock(Vec2 pos_, OBJECT_TYPE obj_)
{
	//!壁を除いた指定箇所にオブジェクト代入
	m_stage[pos_.y + WALL_SIZE][pos_.x + WALL_SIZE].m_obj = obj_;
}

//!予測枠更新関数
void Tetris_Stage::SetUpNextBlock(Vec2 pos_, OBJECT_TYPE obj_)
{
	//!壁を除いた指定箇所にオブジェクト代入
	m_next_block[pos_.y + WALL_SIZE][pos_.x + WALL_SIZE].m_obj = obj_;
}

//!予測枠クリア関数
void Tetris_Stage::NextBlockClear()
{
	memcpy(m_next_block, m_next_block_clear, sizeof(m_next_block_clear));
}

//!ブロック消去判定関数
void Tetris_Stage::SearchDeleteBlock()
{
	//!ステージの下から調べていく
	for (int y = GAME_HEIGHT - (WALL_SIZE + WALL_SIZE); y > 0 + WALL_SIZE; y--)
	{
		for (int x = 0; x < GAME_WIDTH; x++)
		{
			//!固定されたブロックが見つかればカウントする
			if (m_stage[y][x].m_obj == FIXED_BLOCK)
			{
				m_block_counter++;

				//!横一列に揃っている場合
				if (m_block_counter == GAME_WIDTH - (WALL_SIZE + WALL_SIZE))
				{
					DeleteBlock(y);  //!その段を消去
				}
			}
		}

		//!下から見ていって横一列ブロックが配置されてない場合そこで判定を終了する
		if (m_block_counter == 0)
		{
			break;
		}

		m_block_counter = 0;
	}
}

//!ブロック消去関数
void Tetris_Stage::DeleteBlock(__int8 y_)
{
	for (int y = y_; y > 0 + WALL_SIZE; y--)
	{
		for (int x = 0; x < GAME_WIDTH; x++)
		{
			m_stage[y][x].m_obj = m_stage[y - WALL_SIZE][x].m_obj;  //!上の段を消去する段で上書きする
		}
	}
	
}

//!初期化関数(繰り返し)
OBJECT_TYPE Tetris_Stage::SearchStage(Vec2 pos_)
{
	return m_stage[pos_.y + WALL_SIZE][pos_.x + WALL_SIZE].m_obj;
}
